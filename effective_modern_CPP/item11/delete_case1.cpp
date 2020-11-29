#include<iostream>
bool 
constexpr 
isLuck(int number)
{
    switch(number){
        case 1:return false;
        default:return true;
    }
   // return false;
}
bool
isLuck(char)=delete;//reject chars

bool 
isLuck(bool)=delete;//reject bools
bool
isLuck(double)=delete;//reject doubles and floats
//Given a choice between converting a float to an int or to a double,
//C++ prefers the conversion to double.
int main(){
    //if(isLuck('a'));//error:
    //function "isLuck(char)" (declared at line 9) cannot be referenced -- it is a deleted function
    //if(isLuck(false));//error:same reason...
    //if(isLuck(3.8));
    if(isLuck(3));//OK!
    }