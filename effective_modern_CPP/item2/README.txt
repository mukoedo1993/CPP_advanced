Understanding auto template deduction


With only one exception, auto type deduction is template type deduction, because, with only one curious exception, auto type
deduction is template type deduction. 

caveats:
1:auto type deduction is usually the same as type deduction, and auto type deduction assumes that a braced initializer represents a 
std::initializer_list, and template type deduction doesn't.

2: auto in a function return type or a lambda parameter implies template type deduction, not auto type deduction.
