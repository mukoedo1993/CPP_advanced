#include<tuple>
#include<iostream>
using UserInfo=std::tuple<
                          std::string,//name
                          std::string,//email
                          std::size_t>;//reputation

enum UserInfoFields{uiName,uiEmail,uiReputation};
enum struct UserInfoFields1{uiName,uiEmail,uiReputation};

template<typename E>
constexpr typename std::underlying_type_t<E>
    toUType(E enumerator)noexcept
    {
        return 
        static_cast<typename
                    std::underlying_type<E>::type>(enumerator);
    }


    template<typename E>
constexpr 
auto//Rewrite the return type as auto.
    toUType1(E enumerator)noexcept
    {
        return 
        static_cast<typename
                    std::underlying_type<E>::type>(enumerator);
    }
int main()
{
    UserInfo uInfo=std::make_tuple("ni","ma",114514);//object of tuple type
    auto val=std::get<1>(uInfo);//get value of filed 1
    auto val1=std::get<uiEmail>(uInfo);
    
    auto val3=
    std::get<static_cast<std::size_t>(UserInfoFields1::uiEmail)>
    (uInfo);

UserInfoFields1 ob1;
auto val4=
std::get<toUType(UserInfoFields1::uiEmail)>(uInfo);
auto val5=
std::get<toUType1(UserInfoFields1::uiEmail)>(uInfo);
std::cout<<"val: "<<val<<"\nval1: "<<val1<<'\n'<<"\nval3: "
<<"val4: "<<val3<<'\n'<<val4<<'\n'<<"val5: "<<val5;
 /*
 
val: ma
val1: ma

val3: val4: ma
ma
val5: ma
 */
}
