#include<future>
#include<chrono>
#include<iostream>
#include<exception>
int quickComputation()
{
    return 2;
}
int accurateComputation()
{int i=17,j=8;i/=j;
for(int k=0;k<10000;k++);
    return i;}

std::future<int>f;//outside declared because lifetime of accurateComputation()
                  //might exceed lifetime of bestResultInTime()

int bestResultTime()
{
    //define time slot to get the answer:
    auto tp=std::chrono::system_clock::now()+std::chrono::minutes(1);

    //start both a quick and an accurate computation:
    f=std::async(std::launch::async,accurateComputation);
    //force faccurateComputation to start asynchronously now or throw std::system_error
    int guess=quickComputation();

    //give accurate computation the rest of the time slot:
    std::future_status s=f.wait_until(tp);

    //return the best computation 
    if(s==std::future_status::ready)
        return f.get();
        else{
            return guess;//accurateComputation()continues
        }
    //Note that the future f can't be a local object declared inside bestResultInTime()
    //because when the time was too short to finish accurateComputation() the destructor 
}
int main()
{std::cout<<bestResultTime();}
/*
(base) zcw@mukoedo1993:~/C++stdlibrary2nd_ed/Chap18$  g++ two_calcul.cpp  -std=c++11 -pthread -o two_calcul
(base) zcw@mukoedo1993:~/C++stdlibrary2nd_ed/Chap18$ ./two_calcul
2(base) zcw@mukoedo1993:~/C++stdlibrary2nd_ed/Chap18$ 
*/