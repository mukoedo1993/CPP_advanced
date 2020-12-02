#include<thread>
#include<iostream>
#include<cmath>
void doSomething()
{}
int main()
{
    std::thread t(doSomething);//start doSomething() in the background
    t.join();//wait for t to finish (block until doSomething() ends)
}
/*
(base) zcw@mukoedo1993:~/C++stdlibrary2nd_ed/Chap18$  g++ sec18_2_the_low_level_interface.cpp  -std=c++11 -pthread -o sec18_2_the_low_level_interface
(base) zcw@mukoedo1993:~/C++stdlibrary2nd_ed/Chap18$  ./sec18_2_the_low_level_interface
(base) zcw@mukoedo1993:~/C++stdlibrary2nd_ed/Chap18$ 
*/
