#include<iostream>
#include<type_traits>
int main(){
    const int i=18;
    const int & i1=17;
   //int &const i2=i;//error: ‘const’ qualifiers cannot be applied to ‘int&’
   //binding reference of type ‘int&’ to ‘const int’ discards qualifiers
   //qualifiers dropped in binding reference of type "int &" to initializer of type "const int"
}