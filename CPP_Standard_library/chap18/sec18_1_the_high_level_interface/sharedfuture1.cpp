#include<iostream>
#include<future>
#include<thread>
#include<exception>
#include<stdexcept>
using namespace std;
//You can call get() only once. After that ,recall it will result in undefined behavior.
//
int queryNumber()
{
    //read number
    cout<<"read number: ";
    int num;
    cin>>num;

    //throw exception if none
    if(!cin){
        throw runtime_error("no number read");
    }

    return num;
}

void doSomething(char c,shared_future<int> f)
{
    try{
        //wait for number of characters to print
        int num=f.get();//get result of queryNumber()

        for(int i=0;i<num;i++){
            this_thread::sleep_for(chrono::milliseconds(100));
            cout.put(c).flush();
        }
    }
    catch(const exception& e){
        cerr<<"EXCEPTION in thread "<<this_thread::get_id()
        <<": "<<e.what()<<endl;
    }
}

int main()
{
    try{
        //start one thread to query a number
        shared_future<int> f=async(queryNumber);

        //start three threads each processing this number in a loop
        auto f1=async(launch::async,doSomething,'.',f);
        auto f2=async(launch::async,doSomething,'+',f);
        auto f3=async(launch::async,doSomething,'*',f);

        //wait for all loops to be finished
        f1.get();
        f2.get();
        f3.get();
    }
    catch(const exception& e){
        cout<<"\nEXCEPTION: "<<e.what()<<endl;
    }
    cout<<"\ndone"<<endl;
}
//Now, instead of using multiple shared future objects all sharing the same shared state,
//you'd use one shared future object to perform multiple get()'s (one in each thread).


/*
(base) zcw@mukoedo1993:~/C++stdlibrary2nd_ed/Chap18$ ./sharedfuture1
read number: 13
.+*.+*.*+.+*.*+.*+.*+.*+.*+.*+.*+*.+*.+
done
(base) zcw@mukoedo1993:~/C++stdlibrary2nd_ed/Chap18$ ^C
(base) zcw@mukoedo1993:~/C++stdlibrary2nd_ed/Chap18$  ./sharedfuture1
read number: 5
+.*.*+.+*+.*+.*
done
(base) zcw@mukoedo1993:~/C++stdlibrary2nd_ed/Chap18$ ./sharedfuture1
read number: x
EXCEPTION in thread 140695405197056: no number read
EXCEPTION in thread 140695396804352: no number read
EXCEPTION in thread 140695276877568: no number read

done
*/