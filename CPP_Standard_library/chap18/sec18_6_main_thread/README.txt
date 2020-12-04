#include<mutex>
#include<condition_variable>

std::mutex readyMutex;
std::condition_variable readyConVar;
bool readyFlag;

//the working thread:
{
   std::lock_guard<std::mutex>lg(readyMutex);
   readyFlag=true;
}//release lock
readyConVar.notify_one();

....................................................................


//the waiting thread
std::unique_lock<std::mutex>l(readyMutex);
readyConVar.wait(l,[]{return readyflag;});//second parameter is pred(). It will continue, if the second paramter return false, otherwise, true.
