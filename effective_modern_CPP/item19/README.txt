Three important characteristics:
1: std::shared_ptr are twice the size of a raw pointer
2: Memory for the reference count must be dynamically allocated
3: Increments and decrements of the reference count must be atomic. 
4: For another, std::shared_ptr supports derive-to-base pointer conversions that make sense for single
objects, but that open holes in the type system when applied to arrays. For this reason, the std::unique_ptr<T[]>
API prohibits such conversions.
