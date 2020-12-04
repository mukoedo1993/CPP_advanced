#include<condition_variable>
#include<mutex>
#include<future>
#include<thread>
#include<iostream>
#include<queue>

std::queue<int> queue;
std::mutex queueMutex;
std::condition_variable queueConVar;

void provider(int val)
{
    //push different values (val til val+5 with timeouts of val milliseconds into the queue)
     for (int i=0;i<6;++i){
     {
         std::lock_guard<std::mutex>lg(queueMutex);
         queue.push(val+i);
     }//release lock
     queueConVar.notify_one();

     std::this_thread::sleep_for(std::chrono::milliseconds(val));
}
}

void consumer (int num)
{
    //pop values if available (num identifies the consumer)
    while(true){
        int val;
        {
            std::unique_lock<std::mutex>ul(queueMutex);
            queueConVar.wait(ul,[]{return !queue.empty();});
            val=queue.front();
            queue.pop();
        }//release lock
        std::cout<<"consumer "<<num<<": "<<val<<std::endl;
    }
}

int main()
{
    //start three providers for values 100+, 300+ and 500+
    auto p1=std::async(std::launch::async,provider,100);
    auto p2=std::async(std::launch::async,provider,300);
    auto p3=std::async(std::launch::async,provider,300);

    //start two consumers printing the values
    auto c1=std::async(std::launch::async,consumer,1);
    auto c2=std::async(std::launch::async,consumer,2);
}

/*
(base) zcw@mukoedo1993:~/C++stdlibrary2nd_ed/Chap18$ g++ condvar2.cpp -std=c++17 -pthread -o convar2
(base) zcw@mukoedo1993:~/C++stdlibrary2nd_ed/Chap18$ ./convar2
consumer consumer 12: : 
consumer 2: 

consumer 2: 
consumer 1: 
consumer 2: 
consumer 1: 
consumer 2: 
consumer 1: 
consumer 2: 
consumer 1: 
consumer 2: 
consumer 1: 
consumer 2: 
consumer consumer 1:

*/