#include<iostream>
#include<cstring>
class Widget{
    public:
    Widget(){
        std::cout<<"Widget()\n";
    }
    Widget(int ,bool)//ctors not declaring
    {
        std::cout<<" Widget(int ,bool)\n";
    }
    Widget(int,double)//std::initializer_list params
    {
        std::cout<<"  Widget(int,double)\n";
    }
    Widget(std::initializer_list<long double>il)
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
    Widget w1;//calls default ctor
    Widget w2{};//also calls default ctor
    Widget w3{10,false};//most vexing parse! declares a function!

    Widget w4({});//call std::initializer_list ctor
                    //with empty list
    
    Widget w5({});//ditto

}
/*
Widget()
Widget()
 Widget(std::initializer_list<long double>il)
 Widget(std::initializer_list<long double>il)
 Widget(std::initializer_list<long double>il)
*/