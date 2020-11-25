#include<iostream>
#include<type_traits>
decltype(auto) f1()
{
    int x=0;
    return x;
}

decltype(auto) f2()

{
    int x=0;
    return (x);
}
    int main(){
        //Put a parameter inside parenthese will change its decltype.
        std::cout<<std::boolalpha;
        std::cout<<std::is_lvalue_reference<decltype(f1())>::value<<std::endl;
        std::cout<<std::is_rvalue_reference<decltype(f1())>::value<<std::endl;
          std::cout<<std::is_lvalue_reference<decltype(f2())>::value<<std::endl;
        std::cout<<std::is_rvalue_reference<decltype(f2())>::value<<std::endl;
    }

    /*
    
false
false
true
false
    */