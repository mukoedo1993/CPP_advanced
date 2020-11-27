
(base) zcw@mukoedo1993:~/multithreading$ g++ introduction.cc  -std=c++11 -pthread -o introduction.cc
g++: fatal error: input file ‘introduction.cc’ is the same as output file
compilation terminated.
(base) zcw@mukoedo1993:~/multithreading$ g++ introduction.cc  -std=c++11 -pthread -o introduction
(base) zcw@mukoedo1993:~/multithreading$ ./a.out
bash: ./a.out: No such file or directory
(base) zcw@mukoedo1993:~/multithreading$ ./introduction
function1 is called!


oversubscription:
......


Resource Acquisition Is Initialization or RAII, is a C++ programming technique[1][2] which binds the life cycle of a resource that must be acquired before use (allocated heap memory, thread of execution, open socket, open file, locked mutex, disk space, database connection—anything that exists in limited supply) to the lifetime of an object.
