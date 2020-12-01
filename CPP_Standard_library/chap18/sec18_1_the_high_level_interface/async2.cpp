#include<future>
#include<list>
#include<iostream>
#include<exception>
using namespace std;

void task1()
{
    //endless insertion and memory allocation
    //will sooner or later raise an excpetion
    //- BEWARE: this is bad practice
    list<int>v;
    while(true){
        for(int i=0;i<10000000;++i)
        v.push_back(i);
    }
    cout.put(',').flush();
}
int main()
{
    cout<<"starting 2 tasks"<<endl;
    cout<<"~ task1: process endless loop of memory consumption"<<endl;
    cout<<"~ task2: wait for <return> and then for task1"<<endl;

    auto f1=async(task1);//start task1() asynchronously( now or later or never)
    cin.get();//read a character(like getchar())
    cout<<"\nwait for the end of task1: "<<endl;
    try{
        f1.get();
    }catch(std::exception&e)
    {
        cerr<<"EXCEPTION: "<<e.what()<<std::endl;
    }
}

/*
(base) zcw@mukoedo1993:~/C++stdlibrary2nd_ed/Chap18$ g++ async2.cpp  -std=c++11 -pthread -o async2
(base) zcw@mukoedo1993:~/C++stdlibrary2nd_ed/Chap18$ ./async2
starting 2 tasks
~ task1: process endless loop of memory consumption
~ task2: wait for <return> and then for task1
Killed

*/
