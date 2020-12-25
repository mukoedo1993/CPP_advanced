Avoiding Duplication in const and Non-const member functions

mutable is a nice solution to the bitwise-constness-is-not-what-I-had-in-mind problem, but it doesn't solve
all const-related difficulties. For example, suppose that operator[] in TextBlock (and CTextBlock) not only returned
a reference to the appropriate character, it also performed bounds checking, logged access information, maybe even did data
integrity validation. Putting all this in both the const and the non-const operator[] functions (and not fretting that we now have
implicitly inline functions of nontrivial length --see Item 30)yields this kind of monstrosity:

See avoid_duplication.cpp
