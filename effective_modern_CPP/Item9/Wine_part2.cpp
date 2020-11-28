#include<list>
#include<iostream>
#include"allocate11.hpp"

class Wine{
    public:
    
};


namespace std{
   
template<>
class list<Wine,MyAlloc<Wine>>{
    public:
    list():type(WineType::White){}
    list(const list& orig):type(orig.type){}
    ~list()noexcept{std::cout<<"all wines are destroyed! so sad!";
    switch(type){
        case WineType::White:std::cout<<"\nWhite!\n";break;
        case WineType::Red:std::cout<<"\nRed\n";break;
        case WineType::Rose: std::cout<<"\nRose\n";break;
    }
    }
    list& operator=(int i){
        switch(i){
            case 1:type=WineType::Red;break;
            case 2:type=WineType::White;break;
            case 3:type=WineType::Rose;break;
            default:break;
        }
        return *this;
    }

private:
    enum class WineType
    {White, Red, Rose};
    WineType type;
};
}//close the namespace std

template<typename T>
    using MyAllocList18=std::list<T,MyAlloc<T>>;
int main(){
     using std::list;
     list<Wine,MyAlloc<Wine>>beers;
     beers=3;
}