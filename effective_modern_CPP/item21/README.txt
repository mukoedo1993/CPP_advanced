std::make_unique and std::make_shared are two of the three make functions:
functions that take an arbitrary set of arguments, perfect-forward them to the constructor for a 
dynamically allocated object, and return a smart pointer to that object. 

Consider a case:
int computePriority();

processWidget(std::shared_ptr<Widget>(new Widget),
              computePriority());
  We only know that new Widget will be called before the constructon of the shared_ptr. But we don't know when computePriority will be called.
  If computePriority() is called after new Widget created but before the construction of the shared_ptr, then, things will go wrong...
  It might cause memory leak!
 (If the function computePriority throws an exception, then...)
 Use a make_shared here could reduce the risk.


...............................................................
Direct use of new, then requires one memory allocation for the WIdget and a second allocation for the control block. 
But using make_ style function, both two will be allocated in a chunk.


..............................................................................
Page146.cpp discussed the situation between pass shared_ptr as rvalue and lvalue. 



....................................................................................................
Conclusions:
1: Compared to direct use of new, make functions eliminate source code duplication, improve exception safety, and, for std::make_shared
and std::allocate_shared, geenrate code that's smaller and faster.
2: Situtations where use of make functions is inappropriate include the ened to specify custom deleters and a desire to pass braced initializers.
3: For std::shared_ptrs, additional situations where make functions may be ill-advised include(1) classes with custom memory management and (2) system
with memory concerns, very large objects, and std::weak_ptrs that outlive the corresponding std::shared_ptrs.
