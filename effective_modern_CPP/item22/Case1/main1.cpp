#include"widget1.h"
int main(){
          //A trivial client code:
          Widget w;
}
//It won't compile!
//Error code on g++: 
/*
(base) zcw@mukoedo1993:~/effective modern C++/item22$ g++ widget1.cpp widget1.h gadget1.h main1.cpp
In file included from /usr/include/c++/9/memory:80,
                 from widget1.h:1:
/usr/include/c++/9/bits/unique_ptr.h: In instantiation of ‘void std::default_delete<_Tp>::operator()(_Tp*) const [with _Tp = Widget::Impl]’:
/usr/include/c++/9/bits/unique_ptr.h:292:17:   required from ‘std::unique_ptr<_Tp, _Dp>::~unique_ptr() [with _Tp = Widget::Impl; _Dp = std::default_delete<Widget::Impl>]’
widget1.h:2:7:   required from here
/usr/include/c++/9/bits/unique_ptr.h:79:16: error: invalid application of ‘sizeof’ to incomplete type ‘Widget::Impl’
   79 |  static_assert(sizeof(_Tp)>0,
*/