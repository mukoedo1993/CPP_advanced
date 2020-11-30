#define x 114
#include<array>
int main()
{
    int sz;//non-constexpr variable
    //constexpr auto arraySize1=sz;
    constexpr auto arraySize1_=x;//OK
    //std::array<int,sz>data1;//error: the value of sz is not usable in a constant expression
    constexpr auto arraySize2=10;//fine, 10 is a compile-time constant
    
    std::array<int, arraySize2>data2;//fine, arraySize2 is constexpr

    const auto arraySize=sz;//fine, arraySize is const copy of sz
    //std::array<int, arraySize>data;//error! arratSize's value not known at compilation
    
}