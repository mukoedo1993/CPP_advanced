#include<list>
#include<iostream>
#include<algorithm>
#include"allocate11.hpp"
struct Widget{};
//MyAllocList<T> is synonym for std::list<T,MyAlloc<T>>

//With a typedef you will have to do:
template<class T>
struct MyAllocList1{
    typedef std::list<T,MyAlloc<T>> type;
};
typename MyAllocList1<Widget>::type lw;//client code

template<class T>
class Widget1{
    private://Widget1 contains a MyAllocList<T> as a data member.
    typename MyAllocList1<T>::type list;
};
template<typename T>
using MyAllocList=std::list<T,MyAlloc<T>>;
 
int main()
{
 MyAllocList<int>yaju;

  
    yaju.push_back(13);
    yaju.push_front(17);
    std::for_each(yaju.cbegin(),yaju.cend(),[](const int& i){std::cout<<i<<" ";});//17 13
    std::cout<<'\n';
}