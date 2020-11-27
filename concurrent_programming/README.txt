
(base) zcw@mukoedo1993:~/multithreading$ g++ introduction.cc  -std=c++11 -pthread -o introduction.cc
g++: fatal error: input file ‘introduction.cc’ is the same as output file
compilation terminated.
(base) zcw@mukoedo1993:~/multithreading$ g++ introduction.cc  -std=c++11 -pthread -o introduction
(base) zcw@mukoedo1993:~/multithreading$ ./a.out
bash: ./a.out: No such file or directory
(base) zcw@mukoedo1993:~/multithreading$ ./introduction
function1 is called!
