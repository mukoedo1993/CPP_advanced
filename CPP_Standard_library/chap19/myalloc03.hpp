//MyAlloc03.hpp
#include<cstdlib>
#include<cstddef>
#include<limits>
template<typename T>
class MyAlloc1{
    public:
    //type definitions:
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;
    typedef T*              pointer;
    typedef const T*        const_pointer;
    typedef T&             reference;
    typedef const T&       const_difference;
    typedef T              value_type;

    //ctors and dtor.
    //-nothing to do because constructors has no state
    MyAlloc1()throw(){

    }
    MyAlloc1(const MyAlloc1<T>&)throw(){

    }
    template<class U>
    MyAlloc1(const MyAlloc1<U>&)throw(){

    }
    ~MyAlloc1()throw(){

    }
    //allocate but don't initialize num elements of T
    T* allocate(std::size_t n){
    return static_cast<T*>(::operator new (n*sizeof(T)));
    }

    void deallocate(T *p,size_t sz){
        //deallocate memory with global delete
        ::operator delete (p);
    }
    //return address of values
    T* address(T& value)const{
        return &value;
    }
     const  T* address(const T& value)const{
        return &value;
    }
        //return maximum number of elements that can be allocated
        std::size_t max_size()const throw(){
            return std::numeric_limits<std::size_t>::max()/sizeof(T);
        }

 // initialize elements of allocated storage p with value value
    void construct (T* p, const T& value) {
        // initialize memory with placement new
        ::new((void*)p) T(value);
    }
void destroy(T *p)
{
    p->~T();
    //built-in types also have (trivial )destructors! But they don't do anything!
}
template<class U>
struct rebind{
    typedef MyAlloc1<U> others;
};

};
//return that all specializations of this allocator are interchangeable
template<class T1,typename T2>
bool operator==(const MyAlloc1<T1>&,
                const MyAlloc1<T2>&)noexcept{
                    return true;
                }

template<class T1,typename T2>
bool operator!=(const MyAlloc1<T1>&,
                const MyAlloc1<T2>&)noexcept{
                    return false;
                }