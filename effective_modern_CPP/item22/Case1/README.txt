The apparent failure of the Pimpl Idiom using std::unique_ptrs is alarming, because (1) std::unique_ptr is advertised
as supporting incomplete types, and (2) the Pimpl idiom is one of std::unique_ptrs most common use cases. Fortunately, getting
the code to work is easy. All that's required is a basic understanding of the cause of the problem.

The issue arises due to the code that's generated when w is destroyed(e.g. goes out of scope). At that point, its destructor is called. In 
the class definition using std::unique_ptr, we didn't declare a destructor, because we didn't have any code to put into it. In accord with 
the usual rules for the compiler-generated special member functions, the compiler generates a destructor for us. Within that destructor, the compiler
inserts code to call the destructor for Widget's data member pImpl. pImpl is a std::unique_ptr<Widget::Impl>, i.e., a std::unique_ptr using the default 
deleter. The default deleter is a function that uses delete on the raw pointer inside the std::unique_ptr. Prior to using delete, however, implementations
typically have the default deleter employ C++11's static_assert to ensure that the raw pointer doesn't point to an incomplete type. When the compiler generates code for 
the destruction of Widget w, then, it generally encounters a static_assert that fails, and that's usually what leads to the error message, This message is associated
with the point where w is destroyed., because the Widget's destructor, like all compiler-generated special member functions, is implicitly inline. The message itself
often refers to the line where w is created, because it's the source code explicitly creating the object that leads to its later implicit destruction.

To fix the problem, you just need to make sure that at the point where the code to destroy the std::unique_ptr<Widget::Impl> is generated, Widget::Impl is a complete
type. The type becomes complete when its definition has been seen, and Widget::Impl is defined inside widget.cpp.

