/*Array arguments*/
//Array types are different from pointer types, even though they sometimes
//seem to be interchangable. 
//In many contexts, an array decays into a pointer to its first element. This
//decay is what permits code :
#include<iostream>
template<class T>
void f(T param){//template with by-value parameters.

}
template<class T>
void f1(T& param){//template with by-value parameters.
 std::cout<<"template<class T>void f(T& param)\n";
 std::cout<<param[0]<<std::endl;//legal
 //J
}
int main(){
  const  char name[]="J.P. Briggs";//name's type is 
                                    //const char[13]
  const char*ptrToName=name;//array decays to pointer

  /*array to pointer decay rule*/
       f1(name);
}