1: COnceptually, constexpr indiactes a value that;s not only constant, it's known during compilation.

2: constexpr objects: such objects are, in fact, const, and they do, in fact, have values that are known
at compile time.

3: Values known during compulation are previleged. They may be placed in read-only memory. E.g, for example,
and esp. for developers of embedded systems, this can be a feature of considerable importance.
Of broader applicability is that integral values that are constant and known during compilation can be used in 
contexts where C++ requires an integral constant expression. Such contexts include specification of aray sizes.integral
template arguments(inlcuding lengths of std::array objects), enumerator values, alignment sepcifiers, and more. If you want to use
a variable for these kinds of things, you certainly want to declare it constexpr, because then compilers will ensure that it has 
a compile-time value.


4: constexpr objects and functions may be used in a wider range of contexts than non-constexpr objects and functions.
5: constxper is part of an object's or function;s interface.
