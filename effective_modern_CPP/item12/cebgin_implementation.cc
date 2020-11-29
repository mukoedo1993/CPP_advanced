#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<deque>
#include<functional>

//actually, cbegin1 is a copy of implementation of cbegin
template<class C>
auto cbegin1(const C&container)->decltype(std::begin(container))
{
    return std::begin(container);
}
template<class C,typename V>
void findAndInsert(C& container,
                  const V& targetVal,
                  const V& insertVal)
{
    //similarly to std::swap, we use the standardized std::~, but still allow Argument-Dependent
    //Lookup on
    //speicalization or non-template version of cbegin and or cend.
    using std::cbegin;
    using std::cend;
    auto it=std::find(cbegin(container),cend(container),targetVal);
    container.insert(it,insertVal);
}

int main()
{
    std::vector<int>v_i={1,2,3,-4,12,10};
    std::list<int>l_i={1,2,3,-4,12,10};
    std::deque<int>d_i={1,2,3,-4,12,10};
    findAndInsert(v_i,-4,114);
    findAndInsert(l_i,-4,114);
    findAndInsert(d_i,-4,114);
    for_each(std::cbegin(v_i),
    std::cend(v_i),[](int i){std::cout<<i<<std::endl;});
    for_each(std::cbegin(d_i),
    std::cend(d_i),[](int i){std::cout<<i<<std::endl;});
    for_each(std::cbegin(l_i),
    std::cend(l_i),[](int i){std::cout<<i<<std::endl;});
}
/*

1
2
3
114
-4
12
10
1
2
3
114
-4
12
10
1
2
3
114
-4
12
10
*/