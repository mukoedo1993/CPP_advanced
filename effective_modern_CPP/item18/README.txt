Attempting to assign a raw pointer to a std::unique_ptr won't compile. Because it would constitute an implicit conversion
from a raw to a stmart pointer. Such implicit conversions can be problematic, so C++11's smart pointers prohibited them.
