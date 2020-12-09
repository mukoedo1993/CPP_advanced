#include<map>
#include<utility>
#include<functional>
#include<iostream>
//Anyway, the std::map will use std::less, and then use operator< indirectly.
class A{
    friend bool operator<(const A&,const A&)
    {return false;}
};

//method 2: overwrite the specialization for std::less<A1> directly.
class A1{};
namespace std{
    template<>
    class less<A1>{
        public:
       bool operator()(const A1&,const A1&)const{return false;}
    };
}

int main()
{
   std::map<A,int>map;
    A a1,a2,a3,a4;
    map.insert({a1,3});map.insert({a2,4});map.insert({a3,5});map.insert({a4,6});
    std::cout<<std::distance(map.cbegin(),map.cend())<<'\n';//1

   std::map<A1,int>map1;
     A1 a1_,a2_,a3_,a4_;
    map1.insert({a1_,3});map1.insert({a2_,4});map1.insert({a3_,5});map1.insert({a4_,6});
    std::cout<<std::distance(map1.cbegin(),map1.cend())<<'\n';//1
}