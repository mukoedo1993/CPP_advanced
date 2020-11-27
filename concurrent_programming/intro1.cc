#include<iostream>
#include<thread>
using namespace std;

void function1()
{
    std::cout<<"function1 is called!\n";
    
}

class fctor{
    public:
      void operator()(string &msg)
      {
          
          cout<<"from t1 "<<msg<<endl;
          msg="you suck!";
         
      }
};

int main()
{
    string s="where there is no trust, there is no love!";
  
    
   std::thread t1((fctor()),std::ref(s));
   
 t1.join();
 std::cout<<"from main"<<s<<endl;
    return  0;
   
}
/*
(base) zcw@mukoedo1993:~/multithreading$ g++ intro1.cc  -std=c++11 -pthread -o intro1
(base) zcw@mukoedo1993:~/multithreading$ ./intro1
from t1 where there is no trust, there is no love!
from mainyou suck!
*/