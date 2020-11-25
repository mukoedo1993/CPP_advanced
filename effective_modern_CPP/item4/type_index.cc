#include<boost/type_index.hpp>
#include<iostream>
#include<vector>

struct Widget{};

template<typename T>
void f(const T&param)
{
    using std::cout;
    using boost::typeindex::type_id_with_cvr;

    //show T:
    cout<<"T= "
        <<type_id_with_cvr<T>().pretty_name()
        <<"\n";
    
    //show param's type:
    cout<<"param: "
        <<type_id_with_cvr<decltype(param)>().pretty_name()
        <<"\n";
}
  std::vector<Widget>createVec()
  {Widget w1,w2;
      return std::vector<Widget>({w1,w2,w1});
  }        //factory function
int main(){
//this way this works is that the function template boost::typeindex::
//type_id_with_cvr takes a type argument (the type about which we want information)
//and doesn;t remove const, volatile or reference qualifiers(hence the "with_cvr" is
//in the template name). The result is a boost::typeindex::type_index object, whose
//pretty_name member function produces a std::string containing a human-friendly repre
//-sentation of the type. 

  

    const auto vw=createVec();          //init vw w/factory function

    if(!vw.empty())
    f(&vw[0]);
    using std::cout;
    using boost::typeindex::type_id_with_cvr;
    std::cout<< type_id_with_cvr<decltype(&vw[0])>().pretty_name()<<" ";
     std::cout<< type_id_with_cvr<decltype(vw[0])>().pretty_name();
}
//Result:
/*

T= Widget const*
param: Widget const* const&
Widget const* Widget const&
*/

/*
Unlike a pointer, once a reference is bound to an object,
 it can not be "reseated" to another object. 
 The reference itself isn't an object (it has no identity; taking the address of a reference gives you the address of the referent; 
remember: the reference is its referent).
*/