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
     Widget w1(10,true);
 Widget w2(10,true);
 Widget w3(10,5.0);
 Widget w4{10,5.0};
 Widget w5(w4);//uses parens, call copy ctor
 Widget w6{w4};//uses braces, calls
                //std::initializer_list ctor
Widget w7(std::move(w4));//uses parens, calls move ctor
Widget w8{std::move(w4)};//uses braces, std::initializer_list ctor
//converting operator is called.
}

/*

 Widget(int ,bool)
 Widget(int ,bool)
  Widget(int,double)
 Widget(std::initializer_list<long double>il)
 Widget(std::initializer_list<long double>il)
 Widget(std::initializer_list<long double>il)
*/