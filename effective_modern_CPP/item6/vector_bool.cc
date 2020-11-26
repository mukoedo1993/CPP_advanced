#include<vector>
#include<iostream>
#include<boost/type_index.hpp>
#include<bitset>
struct Widget{};
std::vector<bool> features(const Widget&w)
{
    std::vector<bool> v({true,false,true,false,false,false,false,false,false});
    v.flip();
    return v;
}
double constexpr calcEpsilon()
{
    return 3.56;
}
int main()
{
        Widget w;

       auto highPriority =  features(w)[5];
       auto highPriority1 = static_cast<bool>(features(w)[5]);//convertible!!!
       using boost::typeindex::type_id_with_cvr;
        std::cout<<"param: "
        <<type_id_with_cvr<decltype(highPriority)>().pretty_name()
        <<"\n";
        std::cout<<"param: "
        <<type_id_with_cvr<decltype(highPriority1)>().pretty_name()
        <<"\n";
        typedef std::vector<bool>::reference rf;
       
        std::cout<<bool(highPriority);//0 not correct result. Undefined behavior, to 
        //use the rf above directly.
        std::cout<<bool(highPriority1);//1 correct.
         highPriority.~rf();//OK

         auto ep=calcEpsilon();
         std::cout<<'\n'<<type_id_with_cvr<decltype(ep)>().pretty_name()<<"\n";//double

         auto ep1=static_cast<float>(calcEpsilon());
          std::cout<<'\n'<<type_id_with_cvr<decltype(ep1)>().pretty_name()<<"\n";//float

          auto index=3*(features(w).size());
             std::cout<<'\n'<<type_id_with_cvr<decltype(index)>().pretty_name()<<"\n";//unsigned long

          auto index1=static_cast<int>(features(w).size()) ;
           std::cout<<'\n'<<type_id_with_cvr<decltype(index1)>().pretty_name()<<"\n";//int
           std::string str(16,'0');
          std::bitset<16>b(str);
          auto ep2=b[5];

            std::cout<<'\n'<<type_id_with_cvr<decltype(ep2)>().pretty_name()<<"\n";
            //std::bitset<16ul>::reference
            auto ep3=static_cast<bool>(b[5]);
            std::cout<<'\n'<<type_id_with_cvr<decltype(ep3)>().pretty_name()<<"\n";
            //bool;




}