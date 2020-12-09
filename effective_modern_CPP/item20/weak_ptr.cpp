#include<iostream>
#include<unordered_map>
#include<memory>
class Widget{

};
class WidgetID{
   public:
  friend
   bool operator==(const WidgetID&,const WidgetID&){return false;}
   friend
   bool operator==(const std::weak_ptr<WidgetID>&,const std::weak_ptr<WidgetID>&){return false;}
   WidgetID(int j):i(j){}
   WidgetID():i(4){}
   int ID()const{return i;}
   private:
   int i;
};
namespace std{
    template<>
    class hash<WidgetID>{
        public:
        size_t operator()(const WidgetID& wid)const{
              hash<int> caller;
             return caller(wid.ID());
        }
    };
     template<>
    class hash<Widget>{
        public:
        size_t operator()(const Widget&)const{
              
             return 7;
        }
    };
}


std::shared_ptr<const Widget>fastLoadWidget(WidgetID id)
{
    std::weak_ptr<const WidgetID>wptr; WidgetID wid;
    static std::unordered_map<WidgetID,std::weak_ptr<const Widget>> cache;
    auto objPtr=cache[id].lock();//objPtr is std::shared_ptr 
                                //to cached object (or null
                                // if object's not in cache)
    
    if(!objPtr){
       // objPtr=loadWidget(id);
       objPtr=std::shared_ptr<Widget>(new Widget);
        cache[id]=objPtr;
    }
     return objPtr;


}
int main()
{ 
               
}