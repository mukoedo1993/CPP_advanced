//async() provides an interface to let a piece of functionality, a callable object, 
//run in the background as a separate thread, if possible.

//Class future<> allows you to wait for the thread to be finished and provides access to its
//outcome: return value or exception, if any,
int fcnc1(){return 4;}
int fcnc2(){return 7;}
int main()
{
   int i=fcnc1()+fcnc2();
   //This means that the processing of the operands happens sequentially. The program will
   //first call fcnc1() and then call fcnc2() or the other way around (according to language rules,
   //the order is undefined.)


}
