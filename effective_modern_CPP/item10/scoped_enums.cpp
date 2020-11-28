#include<iostream>
#include<vector>
//As a general rule, declaring a name inside curly braces limits the visibility of that
//name to the scope defined by the braces/

enum color{
    black,white,red
};
//auto white=false;//error white already declared in this scope
enum class Color{
    black1,white1,red1
};//black, white, red are scoped to Color
auto white1=false;
std::vector<std::size_t>
primeFactors(std::size_t x)
{
    return std::move(std::vector<std::size_t>(10,13));
}
int main()
{
 //Color c=white1;//error! no enumerator named white in this scope
 Color c1=Color::white1;
 auto c2=Color::white1;//also fine
 color c=red;
 if(c<14.5){//compare Color to double
    auto factors=
    primeFactors(c);
    std::cout<<factors[0]<<'\n';//13
 }
 //if(c1<14.5);//no operator "<" matches these operands -- operand types are: Color < double
 if(static_cast<double>(c1)<14.5){
     auto factors=
      primeFactors(c);
    std::cout<<factors[0]<<'\n';//13
 }
}