#include<stdexcept>
#include<exception>
#include<vector>
#include<iostream>
std::exception_ptr eptr;//object to hold exceptions (or nullptr)
void foo()
{
    std::vector<int>v(2);
    try{
       throw std::out_of_range("nimasile!");
    }catch(...)
    {eptr=std::current_exception();
    
    }    //save exception for further processing
    //current exception: https://en.cppreference.com/w/cpp/error/current_exception
}

void bar    ()
{
    try{
    if(eptr!=nullptr){
         std::cerr<<"eptr!=nullptr here!";
        std::rethrow_exception(eptr);       //process saved exception
        //https://en.cppreference.com/w/cpp/error/rethrow_exception
           
    }
    }
    catch(std::out_of_range oor){std::cerr<<oor.what();}
}
int main()
{
   bar();
    std::cout<<__LINE__<<'\n';
   foo();
   std::cout<<__LINE__<<'\n';
   bar();
}

/*
33
35
eptr!=nullptr here!nimasile!
*/