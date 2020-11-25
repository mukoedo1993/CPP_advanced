#include<iostream>
/*ParamType is Neither a Pointer nor a Reference*/

template<typename T>
void f(T param)//param is now passes by value
{}
template<typename T>
void f1(T param)//param is now passes by value
{
    param=15;
    
}
template<typename T>
void f2(T param)//param is now passes by value
{
    *param=15;
    
}
template<typename T>
void f3(T param)//param is now passes by value
{
    param=nullptr;
    
}

int main(){
    int x=27;
    const int cx=x;
    const int& rx=x;

    f(x);//T and param's type are both int
    f(cx);//T and param's type are again both int
    f(rx);//T and param's type are still both int

    /*
    Note that even though cx and rx represent const values, param isn't const. That
    makes sense. param is an object that's completely indepenedent of cx and rx--a copy
    of cx and rx. The fact that cx and rx can't be modified says nothing about whether param
    can be. That's why expr's constness (and volatileness, if any) is ignored when deducing
    a type for param: just because expr can't be modified doesn't mean  that a copy of it
    can't be.
    It's important to recognize that const (and volatile) is ignored only for by-value parameters.
    As we've seen, for paraemters that are references-to- or pointers-to-const, the constness
    of expr is preserved during type deduction. But consider the case where expr is a const
    pointer to a const object, and expr is passed to a by-value param.
    */
   const char* const ptr="Fun with pointers";
   f(ptr);//pass arg of ype const char*const
   /*
   Here, the const to right of the asterisk declares ptr to be const potr can't be made to
   point to a different location, nor can it be set to null. (The const to the left of the )
   asterisk says that what ptr points to -- the character string --is const, hence can't be modified.
   When ptr is passed to f, the bits making up the pointer are copied into param. As such, the pointer 
   itsefle will be passed by value. In accord with the type deduction rule for by-value parameters, the 
   constness of ptr will be ignored, and the type deduced for param will be const char*, i.e.,
   a modifiable pointer to a const char string. The constness of what ptr points is preserved during type
   deduction, but the constness of ptr itself is ignored when copying it to create the new pointer, param.
   */
  const int i=114;
  const int &rti=i;
 f1(rti);//int
 std::cout<<"now rti is: "<<rti<<std::endl;//114
 const int * ptr_i=&i;

 //f2(ptr_i);//assignment of read-only location ‘* param’
 //now the param of f2 is still a pointer to const-int.
 //Basically, the content to which points to is preserved.


 const int*const cptr_i=&i;
f3(cptr_i);//ok: because we are now copying the pointer and it's value.
//It is a pointer that points to a const int. But its own cv-qualifer is discarded
//in this process.
}
//now rti is: 114