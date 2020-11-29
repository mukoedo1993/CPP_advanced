
Also, remember to add l r value specifier to distinguish two cases.
If you could move construct yet only copy construct option is available, it will be a waste of time and cause unnessary overloading.

Prefer const_iterators to iterators.
In maximally generic code, prefer non-member versions of begin, end, rbegin, etc, over their member function counterparts.
