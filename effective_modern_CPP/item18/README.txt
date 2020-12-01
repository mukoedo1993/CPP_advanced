Attempting to assign a raw pointer to a std::unique_ptr won't compile. Because it would constitute an implicit conversion
from a raw to a stmart pointer. Such implicit conversions can be problematic, so C++11's smart pointers prohibited them.


Stateless function objects (e.g., from lambda expressions with no captures) incur no size penalty, and this means that when a custom
deleter can be implemented as either a function or a captureless lambda expession, the lambda is preferable.
