#include<future>
#include<mutex>
#include<iostream>
#include<string>

std::mutex printMutex; //enable synchronized output with print()

void print(const std::string&s)
{
   std::lock_guard<std::mutex> l(printMutex);
    for(char c:s){
        std::cout.put(c);
    }
    std::cout<<std::endl;
}

int main()
{
    auto f1=std::async(std::launch::async,
    print,"Hello from a first thread");
    auto f2=std::async(std::launch::async,
    print,"Hello from a second thread");
    print("Hello from the main thread");
}
/*
(base) zcw@mukoedo1993:~/C++stdlibrary2nd_ed/Chap18$ g++ mutex1.cpp  -std=c++11 -pthread -o mutex1
(base) zcw@mukoedo1993:~/C++stdlibrary2nd_ed/Chap18$ ./mutex1
Hello from a first thread
Hello from a second thread
Hello from the main thread
(base) zcw@mukoedo1993:~/C++stdlibrary2nd_ed/Chap18$ g++ mutex1.cpp  -std=c++14 -pthread -o mutex1
(base) zcw@mukoedo1993:~/C++stdlibrary2nd_ed/Chap18$ ./mutex1
Hello from the main thread
Hello from a first thread
Hello from a second thread
(base) zcw@mukoedo1993:~/C++stdlibrary2nd_ed/Chap18$ #without a lock:i.e. comment the line 10:
(base) zcw@mukoedo1993:~/C++stdlibrary2nd_ed/Chap18$ g++ mutex1.cpp  -std=c++14 -pthread -o mutex1
(base) zcw@mukoedo1993:~/C++stdlibrary2nd_ed/Chap18$ ./mutex1
Hello from the main thread
Hello fromH ea slelo cfrom a fiornd threads
t thread
(base) zcw@mukoedo1993:~/C++stdlibrary2nd_ed/Chap18$ #
(base) zcw@mukoedo1993:~/C++stdlibrary2nd_ed/Chap18$ #We could see that the sequence is
*/