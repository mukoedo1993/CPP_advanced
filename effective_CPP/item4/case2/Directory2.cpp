#include<iostream>

class Directory{                //created by library client
public:
        Directory(int );

};
Directory::Directory(int)
{
    std::size_t disks=tfs().numDisks();
}