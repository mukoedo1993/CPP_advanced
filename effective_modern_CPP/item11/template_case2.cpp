//ANother trick that deleted functions an perform (and that private member functions
//can't) is to prevent use of template instantiations that should be disabled.
#include<iostream>
#include<type_traits>
template<class T>
void processPointer(T*ptr)
{
    std::cout<<typeid(T).name()<<"is T!\n";
}

template<>
void processPointer<void>(void*)=delete;

template<>
void processPointer<char>(char*)=delete;
//Similarly for const char*, volatile char*, const volatile char*...

//C++98 style cannot give a member function template specialization a 
//different access level from that of the main template.
class Widget{
    public:
   template<class T>
void processPointer(T*ptr)
{
    std::cout<<typeid(T).name()<<"is T within the Widget class!\n";
}
private:

};
template<>
void Widget::processPointer<void>(void*)=delete;//still public, but deleted

int main()
{
    auto it=nullptr;
    Widget ob1;
    //ob1.processPointer(static_cast<void*>(it));//error:use of deleted function ‘void Widget::processPointer(T*) [with T = void]’
     ob1.processPointer(static_cast<Widget*>(it));
     //OK: 6Widgetis T within the Widget class!
}