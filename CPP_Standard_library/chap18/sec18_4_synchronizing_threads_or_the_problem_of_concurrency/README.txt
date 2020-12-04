Sec 18_4:
key word: same data
The only safe way to concurrently access the same data by multiple threads without synchronization is when ALL
threads only READ the data.
By the "same data" I mean data that uses the same memory location. If different threads concurrently access different variables or 
objects or different numbers of them, there is no problem because, since C++11, each variable except a bitfield is guranteed to have its
own memory location. 
*********************************************************************************************************************************************
key word: data race
However, when two or more threads concurrently access the same variable or object or member of it and at least one of the threads performs modifications,
 you can easily get into deep trouble if you don't synchronize that access. This is what is called a data race in C++. In the C++11 standard, a data race
 is defined as "two conflicting actions in different threads, at least one of which is not atomic, and neither happens before the other." A data race always results
always results in undefined behavior.

So, it's probably a good idea to care about concurrent data access if you use multiple threads.

Thus, a standard such as C++ specifies the effect of statements and operations are not the corresponding generated assembler code.

*********************************************************************************************************************************************
keyword: as-if rule
Each compiler can optimize code as long as the behavior of the program visible from the outside behaves the same.
Reorderings can be useful to improve the speed of the program, but they might break the behavior, to be able to benefit from fast speed where useful,
safety is not for default. Thus, esp. for concurrent data accesss, we have to understand which guarantees are given.

*********************************************************************************************************************************************
three most prominent problems in multithreading:
1: unsynchronized data access: When two threads running in parallel read and write the same data, it is open which statements comes first.
2: Half-written data: When one thread reads data, which another thread modifies, the reading thread might even read the data in the middle of the write
of the other thread, thus reading neither the old nor the new value.
3: Reordered statements: statements and operations might be reordered so that the behavior of each single thread is correct, but in combination of all threads,
expected behavior is broken.
4: Unless otherwise stated, C++ standard library functions usually don't support writes or reads concurrently performed with writes to the same data structure.

*********************************************************************************************************************************************
Atomicity: This means that read or write access to a variable or to a sequence of statements happens exclusively and without any interruption, so that
 one thread can't read intermediate state caused by another thread.
 Order: We need some ways to guarantee the order of specific statements or a group of spcific statements.
 
 1: futures
 2:mutexes and locks
 3: condition variables
 4: atomic data types
 5: low-level interface of atomic data types
