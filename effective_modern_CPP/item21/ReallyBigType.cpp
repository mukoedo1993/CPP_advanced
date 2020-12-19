#include<iostream>
#include<memory>

class ReallyBigType{
    //
};

auto pBigObj=                                  //create very large
std::make_shared<ReallyBigType>();             //object via
                                             //std::make_shared
                                
                                //create std::shared_ptrs and std::weak_ptrs to large
                                //object, use them to work with it
                                //final std::shared_ptr to object destroyed here,
                                //but std::weak_ptrs to it remain
                                //during this period, memory formerly occupied by large
                                //object remains allocated
                                //final std::weak_ptr to object destroyed here;
                                //memory for control block and object is released

std::shared_ptr<ReallyBigType>pBigObj1(new ReallyBigType);
                                        //create very large
                                        //object via new
                
                //as before, create std::shared_ptrs and
                //std::weak_ptrs to object, use them with it

                //final std::shared_ptr to object destroyed here,
                //but std::weak_ptrs to it remain;
                //memory for object is deallocated

                //during this period, only memory for the 
                //control block remains allocated

                //final std::weak_ptr to object destroyed here;
                //memory for contorl block is released
int main(){}