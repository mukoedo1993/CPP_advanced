#include<vector>
#include<iostream>
#include"myalloc11.hpp"//remove Chap19, in other case.
//#include"myalloc03.hpp"

int main()
{
    std::vector<int,MyAlloc<int>>v_i(10,23);
  
    v_i.push_back(14);
    v_i.push_back(16);
   
    for(auto i:v_i)
    std::cout<<i<<" ";
    std::cout<<'\n';

}