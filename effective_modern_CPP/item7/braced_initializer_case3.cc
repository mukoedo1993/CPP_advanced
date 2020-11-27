#include<iostream>
#include<cstring>
class Widget{
    public:
    Widget(int ,bool)//ctors not declaring
    {
        std::cout<<" Widget(int ,bool)\n";
    }
    Widget(int,double)//std::initializer_list params
    {
        std::cout<<"  Widget(int,double)\n";
    }
    Widget(std::initializer_list<std::string>il)
    {
        std::cout<<" Widget(std::initializer_list<long double>il)\n";
    }
    constexpr operator  float()const//convert to float
    {
        return 5.2;
    }
};


int main()
{
     Widget w1(10,true);
 Widget w2(10,true);
 Widget w3(10,5.0);
 Widget w4{10,5.0};
}
/*
 Widget(int ,bool)
 Widget(int ,bool)
  Widget(int,double)
  Widget(int,double)
*/