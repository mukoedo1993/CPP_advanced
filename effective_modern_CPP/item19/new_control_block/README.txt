1: std::make_shared always creates a control block.

2: A control block is created when a std::shared_ptr is constructed from a unique_ownership pointer
(i.e., a std::unique_ptr or std::auto_ptr).
Unique-ownership pointers don't use control blocks, so there should be no control block for the pointed-to
object. (As part of its construction, the std::shared_ptr assumes ownership of the pointed-to object, so the unique-
ownership pointer is set to null.

3: When a std::shared_ptr constructor is called with a raw pointer, it creates control block. If you want to create a std::shared_ptr
from an object that already had a control block, you'd presumably pass a std::shared_ptr or a std::weak_ptr as a constructor argument, not a raw pointer.

4: std::shared_ptr contructors taking std::shared_ptrs or std::weak_ptrs as constructor arguments don't create new control blocks, because they can rely
on the smart pointers passed to them to point to any necesary control blocks. 

