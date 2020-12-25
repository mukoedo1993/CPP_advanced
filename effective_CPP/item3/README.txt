Avoiding Duplication in const and Non-const member functions

mutable is a nice solution to the bitwise-constness-is-not-what-I-had-in-mind problem, but it doesn't solve
all const-related difficulties. For example, suppose that operator[] in TextBlock (and CTextBlock) not only returned
a reference to the appropriate character, it also performed bounds checking, logged access information, maybe even did data
integrity validation. Putting all this in both the const and the non-const operator[] functions (and not fretting that we now have
implicitly inline functions of nontrivial length --see Item 30)yields this kind of monstrosity:
static_cast safely cast a non-const to const
const_cast only C++ style way to cast a (low-level) const to a non-const

See avoid_duplication.cpp



.............................................................................................................
Conclusion:
Things to remember:
Declaring something const helps compilers detect usage errors. const can be applied to objects at any scope, to function parameters and
return types, and to member functions as a whole. 
Compilers enforce bitwise constness, but you should program using conceptual constness.
When const and non-const member functions have essentially identical implementations,code duplication can be
avoided by having the non-const version call the const version.
