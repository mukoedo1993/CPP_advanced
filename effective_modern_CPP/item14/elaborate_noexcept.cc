#include<iostream>
#include<stdexcept>
//setup and cleanup and non-noexcept functions
void setup(){
std::cout<<"setup()\n";
}
int i=12;
void cleanup()
{
    if(::i>10)throw std::invalid_argument("hehe");
    std::cout<<"cleanup()\n";
}
//doWork wrapper setup and cleanup as noexcept functions...
void doWork()noexcept{
    setup();
    cleanup();
}
int main(){
    try{
    //doWork();
    cleanup();
    }catch(...)
    {
        std::cerr<<"caught!\n";//not normally stopped
    }
    //If we remove the comment of doWork(), the program will be terminated.
    //However, if we don't, the exception handler will work smoothly.
}