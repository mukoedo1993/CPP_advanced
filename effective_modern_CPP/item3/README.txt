decltype: 

We cannot bind a lvalue reference on a const.

return an auto type.
e.g. let the return value be B. We use the auto to deduct:
auto real_return_value=T&...
real_return_value will be a naked T type variable.
If we use decltype(auto) to return, then T&'s reference will be reserved.

