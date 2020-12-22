#include"widget2.h"
#include"gadget1.h"
#include<string>
#include<vector>
struct Widget::Impl{
std::string name;
std::vector<double> data;
Gadget g1,g2,g3;
};
Widget::Widget():
pImpl(std::make_unique<Impl>())
{
   
}
Widget::~Widget()=default;   //as before
Widget::Widget(Widget&&rhs)=default;
Widget& Widget::operator=(Widget&& rhs)=default;  //definitions  
