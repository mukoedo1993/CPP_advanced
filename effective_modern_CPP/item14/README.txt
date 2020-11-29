...
The difference between unwinding the call stack and possibly unwinding it has a suprisingly large
impact on code generation. In a noexcept function, optimizers need not keep the runtime stack in an undinable state
if an exception would progagate out of the function, nor must they ensure that objects in a noexcept function are destroyed
in the inverse order of construction should an exception leave the function. Functions with "throw()" excption specifications lack 
such optimization flexibility, as do functions with no exception specification at all. 

...
...
By default, all memory deallocation functions and all destructors-- both user-defined and compiler-generated--are implicitly noexcept.

...
A function with a wide contract has no preconditions. Such a function may be called regardless of the state of the program, and it imposes
no constraints on the arguments that callers pass it.
Functions without wide contracts have narrow contracts. For such functions, if a precondition is violated, results are undefined.
