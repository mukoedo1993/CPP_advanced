#include<iostream>
#include<vector>
#include<memory>
template<typename T,
typename... Ts>
void doSomeWork(Ts&&... params)
{
    //create local T object from params...
    T localObject(std::forward<Ts>(params)...);
    std::cout<<localObject.size()<<"\n";//13
     T localObject1{std::forward<Ts>(params)...};
     std::cout<<localObject1.size();//2
}
int main()
{
    std::vector<int>vi={1,2,3,4};
    doSomeWork<std::vector<int>>(13,5);
    
     auto u_p=std::make_unique<std::vector<int>>(13,5);//13
     auto s_p=std::make_shared<std::vector<int>>(13,5);//13
     std::cout<<'\n'<<u_p->size()<<" "<<s_p->size();//

      
     //auto u_p1=std::make_unique<std::vector<int>>{13,5};//error
     //auto s_p1=std::make_shared<std::vector<int>>{13,5};//error
     //std::cout<<'\n'<<u_p1->size()<<" "<<s_p1->size();//

}