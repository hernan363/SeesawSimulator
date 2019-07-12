#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>


using namespace std;

float heightA;
float heightB;

int semaphoreA;
int semaphoreB;

int sawCounter;

//mutex locks
mutex fredLock, wilmaLock;

//ONE SEMAPHORE
// fred is A
void *fredSee(float velocity, int counter) {
  int  count = 0;
  wilmaLock.lock();
  while(counter < 10 ) {
    fredLock.lock();

    cout << "Fred's starting point: " << heightA << endl;
    cout << "Wilma's starting point: " << heightB << endl;

    for(int i = 0; i <= 5; ++i) {
      //checks if he's pushing
      heightA += velocity;
      heightB -= velocity;
      cout << "Fred is going up: " << heightA << endl;
      cout << "Wilma is going down: " << heightB << endl;
      this_thread::sleep_for (chrono::seconds(1));
    }

    ++counter;
    wilmaLock.unlock();
  }
}

void *wilmaSaw(float velocity, int counter) {
  while(counter < 10) {
    wilmaLock.lock();
    for(int i = 0 ; i <= 3; ++i) {
      //checks if she's pushing
      heightB += velocity;
      heightA -= velocity;

      cout << "Fred is going down: " << heightA << endl;
      cout << "Wilma is going up: " << heightB << endl;

      this_thread::sleep_for (chrono::seconds(1));
    }

    cout << endl;
    cout << "See Saw Counter is at: " << counter << endl;
    cout << endl;

    ++counter;


    //pause for 2
    this_thread::sleep_for(chrono::seconds(2));

    fredLock.unlock();
  }
}

int main(int argc, char const *argv[]) {

  //variables
  semaphoreA = 1;
  semaphoreB = 0;

  sawCounter = 1;

  heightA = 1.0;
  heightB = 7.0;

  this_thread::sleep_for(chrono::seconds(2));

  //create threads
  thread fred (fredSee, 1.0, sawCounter);

  thread wilma (wilmaSaw, 1.5, sawCounter);

  //join threads
  fred.join();
  wilma.join();

  //time to go home
  cout << "They are too tired to continue but they had fun!" << endl;

  return 0;
}
