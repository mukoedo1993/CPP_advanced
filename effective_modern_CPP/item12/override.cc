#include<iostream>
#include<memory>
struct Base{
    virtual void doWork(){

    }
    virtual void mf1()const{}
    virtual void mf2(int){}
    virtual void mf3()&{}
    virtual void mf4()const{}
};
class Derived:public Base{
public:
virtual void doWork(){
std::cout<<"Derived::doWork!\n";
}
virtual void mf1()const override{
    std::cout<<"Derived::mf1!\n";
}
virtual void mf2(int x) override;
virtual void mf3()&override{std::cout<<"Derived::mf3!\n";}
    virtual void mf4()const override{std::cout<<"Derived::mf4!\n";}
};
void Derived::mf2(int x)
{
 std::cout<<x<<"in Derived::mf2\n";   
}

int main()
{
   std::unique_ptr<Base>upb=
   std::make_unique<Derived>();
   upb->doWork();
   upb->mf1();
   upb->mf2(13);
   upb->mf3();
   upb->mf4();
}
/*

Derived::doWork!
Derived::mf1!
13in Derived::mf2
Derived::mf3!
Derived::mf4!
*/