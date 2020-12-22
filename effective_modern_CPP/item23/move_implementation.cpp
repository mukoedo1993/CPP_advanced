#include<functional>
#include<type_traits>
#include<iostream>
#include<memory>
template<typename T>
typename std::remove_reference<T>::type&&
Move(T&& arg)
{
   using ReturnType=typename std::remove_reference_t<T>&&;//OK since C++14
   return static_cast<ReturnType>(arg);
}

template<typename T,typename... Args>
std::unique_ptr<T>
Make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

template<typename T>
typename std::remove_reference<T>::type&&
Move1(T&& arg)
{
   using ReturnType=typename std::remove_reference<T>::type&&;//OK since C++11
   return static_cast<ReturnType>(arg);
}

class A{
    public:
    A(int i,int &&j, int&t){
        std::cout<<" A(int i,int &&j, int&t)\n";
    }
    A(int &i,int j,int k){
         std::cout<<" A(int &i,int j, int t)";
    }

};
int main()
{
  std::string str1="nimasi",str2;
  str2=Move(str1);
  std::cout<<str1.size()<<'\n'<<str2<<'\n';

  std::string str1_="nimasi",str2_;
  str2_=Move1(str1_);
  std::cout<<str1_.size()<<'\n'<<str2_<<'\n';
 int i=15;
  auto uptr=Make_unique<A>(13,15,i);
   auto uptr1=Make_unique<A>(i,i,i);
}

/*

0
nimasi
0
nimasi
 A(int i,int &&j, int&t)
 A(int &i,int j, int t)
*/