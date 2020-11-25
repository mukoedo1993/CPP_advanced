#include<iostream>
#include<vector>
#include<deque>
struct Widget{
    public:
    Widget():i(4){}
    Widget& operator=(Widget& rhs){
      return rhs;
    }
    int i;
};
bool f(const Widget&w)//decltype(w) is const Widget&
{return false;}

struct Point{
    int x;//decltype(Point::x) is int
    int y;//decltype(Point::y) is int
};


template<class Container,class Index>       
auto authAndAccess(Container&c,Index i)     
//equal to: ->auto                                       
{
   
    return c[i];
}

template<class Container,class Index>       
auto authAndAccess1(Container&c,Index i)     
->decltype(auto)                                       
{
   
    return c[i];
}

int main(){
//decltype is an odd creature. Given a name or an exception, decltype
//tells you the namr's or the expression's type. Typically, what it tells
//you is exactly what you'd predict.
const int i=0;//decltype(i) is const int

Widget w;//decltype(w) is Widget

if (f(w));//decltype(f(w))is bool

std::vector<int>v={1,0};//decltype(v) is vector int
//vector's operator[] returns a lavlue-reference to int, ith element of it.
if(v[0]==0);//decltype(v[0])is int&

std::deque<int>d={0,1,2,3,4,5,6,7,8,9,130};
//authAndAccess(d,5)=10;//expression must be a modifiable lvalue
std::cout<<d[5]<<std::endl;//5
authAndAccess1(d,5)=10;
std::cout<<d[5]<<std::endl;//10

Widget w_;Widget w1;
const Widget& cw=w_;
auto myWidget1=cw;//myWidget1 is Widget type
myWidget1.i=8;//OK

decltype(auto) myWidget2=cw;//myWidget2 is const Widget&
//myWidget2.i=7;//expression must be a modifiable lvalue
const Widget myWidget3;
//myWidget3.i=13;//expression must be a modifiable lvalue
}
/*

5
10
*/