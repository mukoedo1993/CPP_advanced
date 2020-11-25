#include<iostream>
#include<initializer_list>
#include<type_traits>
#include<vector>

typedef int INT;

/*
auto createIntList->auto()
{
    return {1,2,3};//error: expected initializer before ‘->’ token
}
*/




auto main()->int{
    
    auto x=27;  //case 3 (x is neither ptr nor reference)
    const auto cx=x;//case3 (cx isn't either)
    const auto &cx1=x;//cas 1(rx is a non-universal ref)

    //case 2 wirjs as you'd except:
    auto&& uref1=x;//x is int and lvalue
    auto&& uref2=cx;//cx is const int and lvalue
    
    auto&& uref3=27;//27 is int and rvalue
                    //so uref2's type is const int&
                    //reference collapse && &->&

    
    const char name[]=      //name's type is const char[13]
    "R. N. Briggs";

    auto arr1=name;//ptr-to-array decay. arr1 is const char*

    auto& arr2=name;//arr2's type is 
                    //const char(&)[13]
    

    auto x1=27;//type id int, value is 27
    auto x2(27);//ditto

    auto x3={27};//type is std::initializer_list<int>,
                //value is { 27 }


    auto x4{27};    //ditto
  std::cout<<typeid(x1).name()<<" "<<typeid(x2).name()<<" "<<typeid(x3).name()
  <<" "<<typeid(x4).name()<<std::endl;//i i St16initializer_listIiE i

  /*
  There is due to a special type deduction rule for auto. 
  When the initializer for
  an auto-declared variable is enclosed in braces, 
  the deduced type is a std::initializer
  */
/*
C++14 permits auto to indicate that a function's return type should 
be deduced, and C++14 lambdas may use auto in parameter declarations. However,
these uses of auto employ template deduction, not auto type deduction. So a function with a auto
return type that returns a braced initializer won't compile.
*/
std::vector<int>v;
auto resetV=
[&v](const auto& newValue){v=newValue;};//C++14

//resetV({1,2,3});//error! can't deduce type for{1,2,3}
resetV(std::initializer_list<int>({1,2,3}));//OK

}