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
  std::cout<<"this thread: "<<std::this_thread::get_id()<<'\n';//It will print out current thread's
  //id. 
    
   std::thread t1((fctor()),std::ref(s));
   cout<<t1.get_id()<<endl;
   std::thread t2(std::move(t1));//we must call move construtor, otherwise, it will not
   //compile.
   
 t2.join();//t1 is empty now...
 std::cout<<"from main"<<s<<endl;
  std::cout<<"this thread: "<<std::this_thread::get_id()<<'\n';//It will print out current thread's
  //id. 
    return  0;
   
}

/*
g++ intro2.cc  -std=c++11 -pthread -o intro2
(base) zcw@mukoedo1993:~/multithreading$ ./inrto2
bash: ./inrto2: No such file or directory
(base) zcw@mukoedo1993:~/multithreading$ ,.intro2
,.intro2: command not found
(base) zcw@mukoedo1993:~/multithreading$ ./intro2
this thread: 140164046501696
from t1 where there is no trust, there is no love!
from mainyou suck!
this thread: 140164046501696
*/