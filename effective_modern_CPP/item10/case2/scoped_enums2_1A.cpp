#include"scoped_enums2.hpp"
#include<cstdint>
enum class Status:long long int{
good=0,
failed=1,
incomplete=100,
corrupted=200,
audited=500,
indeterminate=0xFFFFFFFF
};//Ok, overwrite it.
//g++ -o case1 scoped_enums2_1A.cpp scoped_enums2.cpp scoped_enums2.hpp
int main(){}