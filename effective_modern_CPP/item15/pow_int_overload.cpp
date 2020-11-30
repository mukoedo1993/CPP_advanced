#include<iostream>
#include<array>
constexpr 
int pow(int base,int exp)noexcept
{
    if(exp>0)
    return base*pow(base,exp-1);
    else if(exp==0)
    return 1;
    else
    return 0;
}
constexpr 
int pow1(int base,int exp)noexcept
{
    auto result=1;
    for(int i=0;i<exp;++i)
    result*=base;
    return result;
}
int
constexpr
readFromDB(const char*)
{
    return 4;
}
int main()
{
    constexpr auto numConds=5;//#of conditions

    std::array<int,pow(3,numConds)>results;//results has 3^numCOnds
    //elements

//Of base and
    auto base=readFromDB("base");
    auto exp=readFromDB("exponent");
    auto baseToExp=pow1(base,exp);
    std::cout<<baseToExp<<" \n";//256
}
