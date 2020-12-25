#include<iostream>
class FileSystem{       //from your library
public: 

std::size_t numDisks()const
{
    return 17;
}       //one of many member functions


};

 FileSystem& tfs()
 {
     static FileSystem fs;
     return fs;
 }          //object for clients to use;
                                //"tfs" = "the file system"

