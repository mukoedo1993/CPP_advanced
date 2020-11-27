#include<iostream>
#include<thread>
using namespace std;

void function1()
{
    std::cout<<"function1 is called!\n";
    
}

class fctor{
    public:
      void operator()(string msg)
      {
          
          cout<<"from t1 "<<msg<<endl;
         
      }
};

int main()
{
    string s="where there is no trust, there is no love!";
  
    
   std::thread t1((fctor()),s);//t1 starts running
    //t1.join();//main thread wait for t1 to finish, if you remove the comment on it.
    t1.detach();//It severed the connection between the main thread and t1
    //t1 will run freely on its own -- t1 becomes a daemon process.
    //the main thread runs so fast that t1 is too late to print its own message.
     //RAII(Resource acquisition is initialization)
        //wrapper w(t1);

   
    try{
   
        cout<<"from main: "<<s<<endl;
  
    }catch(...){
        t1.join();
       throw;
   
    }
    //if(t1.joinable())//false
 t1.join();//No! Once detached, forever detached. Program detached.!
    return  0;
   
}

//a parameter to a thread is always by value...
/*
result:
(base) zcw@mukoedo1993:~/multithreading$ g++ introduction.cc  -std=c++11 -pthread -o introduction
(base) zcw@mukoedo1993:~/multithreading$ ./introduction
from t1 where there is no trust, there is no love!from main: 
where there is no trust, there is no love!
terminate called after throwing an instance of 'std::system_error'
  what():  Invalid argument
*/