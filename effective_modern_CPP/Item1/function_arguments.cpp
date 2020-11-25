#include<iostream>
#include<type_traits>
//constexpr 
void someFunc(int i,double d){
    std::cout<<i<<" "<<d<<" "<<std::endl;
}

template<typename T>
void f1(T param){
    param(13,12.5);
    (*param)(13,12.5);
    std::cout<<std::is_pointer<T>::value<<std::endl;//true
    std::cout<<"void f1(T param)\n";
}

template<typename T>
void f2(T& param){
    param(13,12.5);
    (*****param)(13,1.25);//every time param is converted to a pointer automatically.
      std::cout<<std::is_pointer<T>::value<<std::endl;//false
    std::cout<<"void f2(T& param)\n";
}

int main(){
    std::cout<<std::boolalpha;
f1(someFunc);//param deduced as ptr-to-func.
//type is void(*)(int,double)


f2(someFunc);//param deduced as ref-to-func
//type is void(&)(int, double)

//It passed!
}