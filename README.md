David Hernandez


herna363@mail.chapman.edu


written in c++



Intructions:

compile the file by typing in --> make

run by typing in --> ./a.out


In this assignment I found it was necessary to use a Boolean semaphore which is
essentially a mutex lock. C++ provides a whole library dedicated to mutex locks
so there was plenty of functionality for me to use. Wilma and Fred both have
different leg strengths so I made each of them control the speed they rose and
the speed their partner went down. This would cause both sides to switch roles
consistently when using one mutex lock for Fred and Wilma each. In the
beginning, Fred locks both his and Wilma’s locks, to force Wilma to wait.
When Fred is finished getting to the top and Wilma is at the bottom, it unlocks
Wilma’s lock so she can start going up. Finally, when Wilma is finished, she
unlocks Fred’s lock and it repeats until they have gone 10 times.
