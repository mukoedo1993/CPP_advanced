For case 3:
we want to write a function that takes an enumerator and returns its corresponding std::size_t
value, but it's a littele tricky. std::get is a template, and the value you provide is a template
argument (notice the use of angle brackets, not parentheses), so the function that transforms an enumerator into
a std::size_t has to produce its result during compilation, ...that means it must be a constexpr function.

std::underlying_type<T>::type: if T is an enum type, it will return us the underlying type for the enum type.

For case 4:
Scoped enums may always be forward-declared. Unscoped enums may be forward-declared only if their declaration
specifies an underlying type.
