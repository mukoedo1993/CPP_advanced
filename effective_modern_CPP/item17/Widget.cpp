#include<iostream>
class A{};
class Widget{
    public:
    template<class T>
    Widget(const T&rhs){std::cout<<"non-synthesized template constructor!\n";}//non-big-five

    template<class T>
    Widget operator=(const T&rhs){std::cout<<"non-syntheszied template copy assignment!\n";}

};

int main()
{
    A a;
    //default constructor of Widget was suppressed by a user-defined non-big-five constructor.
    std::cout<<__LINE__;Widget w(a);
    std::cout<<__LINE__; Widget w1=w;//used synthesized copy constructor here.
     /*
     17non-synthesized template constructor!
18
     */
}