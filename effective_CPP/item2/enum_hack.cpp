//Two reasons:
//1: It's legal to take the address of a const, but it's not legal to
//take the address of a const, but it's not legal to take the address of an enum,
//and it's typically not legal to take the address of a #define, either.
#include<iostream>
//call f with maximum of a and b
#define f(a) a-7
#define CALL_WITH_MAX(a,b) f((a)>(b)?(a):(b))

//template inline
//You can get all the efficiency of a macro plus all the predictable
//behavior and type safety of a regular function by using a template for an 
//inline function:
class GamePlayer{
    public:
   
     void print()
     {
         std::cout<<static_cast<int>(this->NumTurns);
     }     
   
    private:
    enum{NumTurns=5};//"the enum hack" -
};

template<typename T>
inline void callWithMax(const T&a,const T&b)
{
    f(a>b?a:b);
}

int main()
{
    int a=5,b=0;
    CALL_WITH_MAX(++a,b);//a is incremented twice
    std::cout<<a<<std::endl;//7
    CALL_WITH_MAX(++a,b+10);//a is incremented only once
    std::cout<<a<<std::endl;//8

    callWithMax(a,b);//OK
    GamePlayer().print();//5
}