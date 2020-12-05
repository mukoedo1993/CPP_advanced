Three important characteristics:
1: std::shared_ptr are twice the size of a raw pointer
2: Memory for the reference count must be dynamically allocated
3: Increments and decrements of the reference count must be atomic. 
