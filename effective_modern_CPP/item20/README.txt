If loadWidget is an expensive call (e.g., because it performs file or database I/O) and it's common for IDs to be used
repeatedly, a reasonable optimization would be to write a function that does what loadWidget does, but also caches its results.
Clogging the cache with every Widget that has ever been requrested can lead to performance problems of its own, however, so another
reasonable optimization would be to destroy cached Widgets when they're no longer in use.
For this caching factory function, a std::unique_ptr return type is not a good fit. Callers should certainly receive smart pointers to cached objects,
and callers should certainly determine the lifetime of those objects, but the cache needs a pointer to the objects, too. The cache's pointer need to be detected
when they dangle, because when factory clients are finished using an object returned by the factory, that object will be destroyed, and the corresponding cache 
entry will dangle. The cached pointers should therefore be std::weak_ptrs-- pointers can detect when they dangle)
That means that the factory's return type should be a std::shared_ptr, because std::weak_ptrs can detect when they dangle only when an object;s lifetime is managed by
std::shared_ptrs.
