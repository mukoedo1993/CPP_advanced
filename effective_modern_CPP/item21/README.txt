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
