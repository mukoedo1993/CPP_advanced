//return size of an array as a compile-time constant. The 
//array parameter has no same, because we care only about the number
//of elements it contains.
#include<iostream>
template<typename T,std::size_t N>
constexpr 
std::size_t arraySize(T(&)[N])noexcept
{
    return N;
}

//declaring function constexpr makes its result available during compilation.

int main(){
    int keyVals[]={1,3,7,9,11,22,35};
    int mappedVals[arraySize(keyVals)];
    std::cout<<sizeof(mappedVals)/sizeof(*mappedVals);//7
}


//Of course, as a modern C++ developer, you'd naturally prefer a std::array to
//a built-in array.

//As for arraySize being declared noexcept, that's to help compilers generate better
//code.