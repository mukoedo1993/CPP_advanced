#include<memory>
#include<vector>
class Widget{
    public:
    Widget(){
        int j=0;

        for(int i=0;i<10000;i++)
            (v[i])=i;
    }
    ~Widget(){}
    private:
     int v[10001];

};

void cusDel(Widget* it)
{
   delete it;
}
void processWidget(std::shared_ptr<Widget>spw,
                   int priority){

                   }
int constexpr computePriority()
{
    return 17;
}
int main() 
{
   std::shared_ptr<Widget>spw(new Widget,cusDel);
   processWidget(spw, computePriority());//not optimized
   processWidget(std::move(spw),computePriority());//optimized...
   /*
   Both efficient and exception safe
   */
  //For the line 33, because processWidget's std::shared_ptr parameter is passed
  //by value, construction from an rvalue entails only a move, while construction from
  //an lvalue requires a copy. For std::shared_ptr, the difference can be siginicant, 
  //because copying a std::shared_ptr requires an atomic increment of its reference count,
  //while moving a std::shared_ptr requires no reference count manipulation at all. For
  //the exception-safe code to achieve the level of performance of the exception-unsafe code.
}
