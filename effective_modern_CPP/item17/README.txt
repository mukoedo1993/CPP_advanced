Memberwise moves are, in reality, more like memberwise move requests, because types that aren't move-enabled will 
be "moved" via their copy operations.

A memberwise move consists of move operations on data members and base classes that support move operations, but a copy operations
for those that don't.

The two move operations are not independent. If you declare either, that prevents compilers from generating the other.
MOve operations won't be generated for any class that explicitly declares a copy operation.

Declaring a move operation (construction or assignment) in a class causes compilers to disable the copy operations. ... After all, if memberwise move
isn't proper way to move an object, there's no reason to expect that memberwise copy is the proper way to copy it.

neither user-defined copy operations, move operations nor destructors definitions allowed for the synthesized move operations.

Widget.cpp : the relation between template assignment operator/constructors with big-fives.
Base.cc: how importance the default and other keywords work. 
