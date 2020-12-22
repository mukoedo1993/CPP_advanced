When we apply a delete operator on a raw pointer, the type of object to which the pointer points must be a complete type.
The synthesized destructor is implicitly inline, so, in the destrutor's eye, the object (with only declaration within the block of class)
might be incomplete. To resolve such a problem, we need to define the destructor and other essential copy control members outside. 



...................................................................................................................
  The Pimpl Idiom decreases build times by reducing compilation dependencies between class clients and class implementations.
  
  For std::unique_ptr pImpl pointers, declare special member functions in the class header, but implement them in the implementation file.
  Do this even if the default function implementations are acceptable.
  
  The above advice applies to std::unique_ptr, but not to std::shared_ptr.
