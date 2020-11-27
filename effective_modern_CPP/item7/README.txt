A novel feature of braced initialization is that it prohibits implicit narrowing conversions 
among built-in types. 


To drawback to braced initialization is the sometimes-surprising behavior that accompanies it. Such 
behaviro grows out of the unusually tangled relationship among braced initializers, std::initializer_list,
and constructor oberload resolution.

braced_initializer_case2.cpp
Here, compilers will ignore the first two constructors (the second of which offers an exact match 
on both argument types) and try to call the constructor taking std::initializer_list<bool>. Calling that constructor would
require coverting an int(10) and a double(5.0) to bools. Both conversions would be narrowing (bool can't exactly represent either value)
,and narrowing conversions are prohibited inside braced initializers, so the call is invalid, and the code is rejected.

braced_initializer_case3.cc
If the user_defined and built-in type conversion does not exist, the compiler will turn to other ordinary constructors.

