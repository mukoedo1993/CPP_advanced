#include<iostream>
#include<memory>
#include<vector>
#include<functional>
class Widget;
std::vector<std::shared_ptr<Widget>>processedWidgets;
class Widget:public std::enable_shared_from_this<Widget>{
    public:
    template<class... Ts>
    static std::shared_ptr<Widget> create(Ts&&... params)
    {
        return std::shared_ptr<Widget>(new Widget(std::forward<Ts>(params)...));
    }
    void process();
    void process1();
    private:
    Widget(){}
    Widget(int,double){}
};
void makeLogEntry(Widget *){}
auto loggingDel=[](Widget *pw)
                    {
                        makeLogEntry(pw);
                        delete pw;
                    };
void Widget::process()
{
    processedWidgets.emplace_back(shared_from_this());
}
void Widget::process1()
{
    processedWidgets.emplace_back(this);
}
class A{};
class B:public A{};
int main(){
    //
        auto item1=Widget::create(); auto item2=Widget::create(13,6.5);
        auto item3=Widget::create();
        //Item1, item2 and item3 are already shared_ptr<Widgets>.
        //If we call their process1 function respectively, it will build up a new 
        //shared_ptr based the this pointer which also has a new control block.
        //It is an error for one naked pointer to have two control blocks.
    item1->process();item2->process();item3->process();

    A* aptr=new A[10]; B *bptr=new B[10];
   
    //std::unique_ptr<A[]>aptr_(bptr);
    //no instance of constructor "std::unique_ptr<_Tp [], _Dp>::unique_ptr 
    //[with _Tp=A, _Dp=std::default_delete<A []>]" matches the argument list -- argument types are: (B *)
     delete[] aptr;delete[] bptr;
     aptr=bptr=nullptr;
}


