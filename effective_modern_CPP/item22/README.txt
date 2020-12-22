When we apply a delete operator on a raw pointer, the type of object to which the pointer points must be a complete type.
The synthesized destructor is implicitly inline, so, in the destrutor's eye, the object (with only declaration within the block of class)
might be incomplete. To resolve such a problem, we need to define the destructor and other essential copy control members outside. 
