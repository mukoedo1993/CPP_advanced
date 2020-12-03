#include<thread>
#include<future>
#include<iostream>
void doSomething(int i,char c)
{
 
}
int main()
{
    std::thread t1(doSomething,5,'.');
    std::thread t2(doSomething,5,'+');
    std::thread t3(doSomething,5,'*');
    std::cout << "t3 ID:    "<<t3.get_id()<<std::endl;
    std::cout<<"main ID:    "<<std::this_thread::get_id()<<std::endl;
    std::cout<<"nothread ID: "<<std::thread::id()<<std::endl;
    t1.join();
    t2.join();
    t3.join();
}

/*
g++ thread_ids.cpp -std=c++11 -pthread -o thread_ids
(base) zcw@mukoedo1993:~/C++stdlibrary2nd_ed/Chap18$ ./thread_ids
t3 ID:    140395522324224
main ID:    140395673331520
nothread ID: thread::id of a non-executing thread
(base) zcw@mukoedo1993:~/C++stdlibrary2nd_ed/Chap18$ 
*/