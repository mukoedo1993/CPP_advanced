#include<atomic>    //for atomics
#include<future>    // for async() and futures
#include<thread>    //for this_thread
#include<iostream>

long data;
std::atomic<bool> readyFlag;

void provider()
{
    //after reading a character
    std::cout<<"<return>"<<std::endl;
    std::cin.get();

    //provide some data....
    data=42;

      // Here, thread provider() first provides some data and then uses a store()
    // to signal that the data is provided:
    //(from line 15:.... )and signal readiness
    readyFlag.store(true);
    //Atomically replaces the current value with desired.
    // Memory is affected according to the value of order.
}


void consumer()
{
    //wait for readiness and do something else
    while(!readyFlag.load()){
        //atomic<T>::load: Atomically loads and returns the current value of the atomic variable. 
        //Memory is affected according to the value of order.
        //return the loaded value
        std::cout.put('.').flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    //and process provided data
    std::cout<<"\nvalue : "<<data<<std::endl;
}

int main()
{
    //store provider and consumer
    auto p=std::async(std::launch::async,provider);
    auto c=std::async(std::launch::async,consumer);

   
  
}

/*
(base) zcw@mukoedo1993:~/C++stdlibrary2nd_ed/Chap18$ g++ atomics1.cpp -std=c++14 -pthread -o atomics1
(base) zcw@mukoedo1993:~/C++stdlibrary2nd_ed/Chap18$ ./atomics1
<return>
value : 
42
*/