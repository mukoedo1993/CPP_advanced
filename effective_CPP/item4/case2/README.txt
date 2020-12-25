Fortunately, a small design change eliminates the problem entirely. All that has to be done is to move each non-local static
object into its own function, where it's declared static. These functions return references to the objects they contain. Clients then call
the functions instead of referring to the objects. In other words, non-local static objects are replaced with local static objects.
(Aficionados of design patterns will recognize this as a common implementation of the Singleton pattern).

This approach is founded on C++'s guarantee that local static objects are initialized when the object's definition is first encountered during
a call to that function. So, if you replace direct accesses to non-local static objects with calls to functions that return references to local static 
objects, you're guaranteed that the references you get back will refer to initialized objects. As a bonus, if you never call a function emulating a non-local
static object, you never incur the cost of constructing and destructing the object, something that can't be said for true non-local static objects.

KEYWORD: singleton pattern
