#include<tuple>
#include<iostream>
using UserInfo=std::tuple<
                          std::string,//name
                          std::string,//email
                          std::size_t>;//reputation

enum UserInfoFields{uiName,uiEmail,uiReputation};
enum struct UserInfoFields1{uiName,uiEmail,uiReputation};
int main()
{
    UserInfo uInfo=std::make_tuple("ni","ma",114514);//object of tuple type
    auto val=std::get<1>(uInfo);//get value of filed 1
    auto val1=std::get<uiEmail>(uInfo);
    
    auto val3=
    std::get<static_cast<std::size_t>(UserInfoFields1::uiEmail)>
    (uInfo);
std::cout<<"val: "<<val<<"\nval1: "<<val1<<'\n'<<"\nval3: "<<val3<<'\n';
    /*
val: ma
val1: ma

val3: ma
    */
}
