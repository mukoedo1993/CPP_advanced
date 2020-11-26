#include<type_traits>
#include<iostream>
#include<memory>
struct Widget{
    friend bool operator<(const Widget&,const Widget&)
    {
        return true;
        }
};
template<class It>//algorithm to dwim("do what I mean")
void dwim(It b,It e)//pre-c++11 style code
{
    while(b!=e){
        typename std::iterator_traits<It>::value::type
        currValue=*b;//auto is not supported...
    }
}

template<class It>//C++11 style
void dwim1(It b,It e)
{
    while(b!=e)
    auto currValue=*b;
}

int main(){
    auto derefUPLess=
    [](const std::unique_ptr<Widget>&p1,//comparison func
       const std::unique_ptr<Widget>&p2)  //for widgets
    {return *p1<*p2;};

    //In C++14, parameters to lambda expressions may involve auto:
    auto derefLess=
    [](const auto&p1,
    const auto&p2)
    {return *p1<*p2;};

    
}