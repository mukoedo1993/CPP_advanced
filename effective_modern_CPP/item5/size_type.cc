#include<iostream>
#include<vector>
#include<unordered_map>
#include<utility>
//Some interesting consequences on std::size_t

int main()
{
    std::vector<int>v={1,-2,3,14,-25,89,0};
    std::unordered_map<std::string,int>m;
    m.insert({"tsr",13});m.insert({"tsr1",15});
    //case 1:
    for(const std::pair<std::string,int>&pr:m)
        std::cout<<pr.first<<" "<<pr.second<<" ";
        //case 1 will succeed by creating a temporary object of the 
        //type that pr wants to bind to by copying each object in m, then
        //binding the reference p to that temporary object. At the end of each
        //loop iteration, the temporary object will be destroyed.
    std::cout<<"\n";
    for(const auto&pr:m){
        std::cout<<pr.first<<" "<<pr.second<<" ";
        auto it1=&pr;
        std::cout<<it1<<" ";
        std::cout<<it1->second<<" ";//OK, we got the address.
    }
}