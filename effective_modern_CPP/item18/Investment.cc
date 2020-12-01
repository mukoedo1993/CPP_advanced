#include<memory>
#include<iostream>
#include<functional>
#include<vector>
class Investment{
    public:
    Investment()=default;
    Investment(int,int,int){}
    virtual ~Investment(){}
};
class Stock:public Investment{};
class Bond:
public Investment{};
class RealEstate:
public Investment{};
template<typename... Ts>
std::unique_ptr<Investment>//retur std::unique_ptr
makeInvestment(Ts&&... params)
{
    return std::make_unique<Investment>(Ts(params)...) ;
}//to an object created from the given args
//std::function<void(Investment*)> 
auto delInvmt=[](Investment* PInvestment)->void
{
    std::cout<<"user-defined deleter!\n";
    delete PInvestment;
};
template<typename... Ts>
std::unique_ptr<Investment,decltype(delInvmt)>
makeInvestment1(char c, Ts&&... params)
{
    RealEstate rl;
    std::unique_ptr<Investment,decltype(delInvmt)>uptr(nullptr,delInvmt);
    if(c=='r'){std::cout<<"A realestate trade created!\n";
        uptr.reset(new RealEstate( std::forward<Ts>(params)...));}
     if(c=='b'){std::cout<<"A bond trade created!\n";
        uptr.reset(new Bond(std::forward<Ts>(params)...));}
        if(c=='s'){std::cout<<"A stock trade created!\n";
        uptr.reset(new Stock(std::forward<Ts>(params)...));}
  return uptr;
}
template<typename... Ts>
auto//OK. 
makeInvestment2(char c, Ts&&... params)
{
    RealEstate rl;
    std::unique_ptr<Investment,decltype(delInvmt)>uptr(nullptr,delInvmt);
    if(c=='r'){std::cout<<"A realestate trade created!\n";
        uptr.reset(new RealEstate( std::forward<Ts>(params)...));}
     if(c=='b'){std::cout<<"A bond trade created!\n";
        uptr.reset(new Bond(std::forward<Ts>(params)...));}
        if(c=='s'){std::cout<<"A stock trade created!\n";
        uptr.reset(new Stock(std::forward<Ts>(params)...));}
  return uptr;
}
template<typename... Ts>
auto//OK. 
makeInvestment3(char c, Ts&&... params)
{
    RealEstate rl;
    std::unique_ptr<Investment,void(*)(Investment*)>uptr(nullptr,delInvmt);
    if(c=='r'){std::cout<<"A realestate trade created!\n";
        uptr.reset(new RealEstate( std::forward<Ts>(params)...));}
     if(c=='b'){std::cout<<"A bond trade created!\n";
        uptr.reset(new Bond(std::forward<Ts>(params)...));}
        if(c=='s'){std::cout<<"A stock trade created!\n";
        uptr.reset(new Stock(std::forward<Ts>(params)...));}
  return uptr;
}
int main(){
    {
        auto pInvestment=
        makeInvestment(13,14,15);
        
        makeInvestment1('s');std::cout<<__LINE__<<'\n';
        makeInvestment1('b');std::cout<<__LINE__<<'\n';
        makeInvestment1('r');std::cout<<__LINE__<<'\n';
        makeInvestment1('k');std::cout<<__LINE__<<'\n';

                makeInvestment2('s');std::cout<<__LINE__<<'\n';
        makeInvestment2('b');std::cout<<__LINE__<<'\n';
        makeInvestment2('r');std::cout<<__LINE__<<'\n';
        makeInvestment2('k');std::cout<<__LINE__<<'\n';


          makeInvestment3('s');std::cout<<__LINE__<<'\n';
        makeInvestment3('b');std::cout<<__LINE__<<'\n';
        makeInvestment3('r');std::cout<<__LINE__<<'\n';
        makeInvestment3('k');std::cout<<__LINE__<<'\n';
    
        //Also, it is easy and convenient to converge a unique_ptr to a shared_ptr
        std::shared_ptr<Investment>sptr=makeInvestment3('k');
    }
}
/*

A stock trade created!
user-defined deleter!
75
A bond trade created!
user-defined deleter!
76
A realestate trade created!
user-defined deleter!
77
78
A stock trade created!
user-defined deleter!
80
A bond trade created!
user-defined deleter!
81
A realestate trade created!
user-defined deleter!
82
83
A stock trade created!
user-defined deleter!
86
A bond trade created!
user-defined deleter!
87
A realestate trade created!
user-defined deleter!
88
89
*/