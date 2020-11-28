#include<vector>
#include<iostream>

#include"myalloc03.hpp"
int main()
{
    std::vector<int,MyAlloc1<int>>v_i(23,9);
  
    v_i.push_back(14);
    v_i.push_back(16);
   
    for(auto i:v_i)
    std::cout<<i<<" ";
    std::cout<<'\n';

}