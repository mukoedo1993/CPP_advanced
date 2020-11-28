myalloc03.hpp is a custom allocator in C++03 standard.(C++11 also OK)
myalloc11.hpp is a custom alloctor in C++11 standard.
Only default construtor, template constructor, (notice that here the synthesized copy constructor isn't suppressed here.)
typename type_value, allocate function and deallocate function
need to be explicitly defined here. Non-member functions are also required, but are only relation operators(equality and non-equality).

C++03 standard requires a much more complex custom allocator. 

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
Operator new and new are two different operators!!!!!!
https://stackoverflow.com/questions/1885849/difference-between-new-operator-and-operator-new#:~:text=The%20difference%20between%20the%20two,object%20created%20in%20that%20memory.
