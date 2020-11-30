#include<iostream>
#include<map>
class Base{
public:
virtual ~Base()=default;//make dtor virtual
Base(Base&&)=default;                       //support moving
Base& operator=(Base&&)=default;

Base(const Base&)=default;                  //support copying
Base& operator=(const Base&)=default;

};
class StringTable{
public:
friend std::ostream& operator<<(std::ostream&os,const StringTable& orig)
{   for(auto it=orig.values.cbegin();it!=orig.values.cend();it++)
    os<<"First element: "<<it->first<<". Second element:"<<it->second<<'\n';

    return os;
}
    StringTable(){}
                    //functions for insertion, erasure, lookup,
                    //etc., but no copy/move/dtor functionality
    void insert(int i,const std::string&orig)
    {values.insert({i,orig});}
private:
    std::map<int,std::string>values;
};//StringTable1 still has synthesized move operations.

class StringTable1{
public:
friend std::ostream& operator<<(std::ostream&os,const StringTable1& orig)
{   for(auto it=orig.values.cbegin();it!=orig.values.cend();it++)
    os<<"First element: "<<it->first<<". Second element:"<<it->second<<'\n';
    return os;}

~StringTable1()
{
    makeLogEntry("Creating StringTable object");//added
    
}
    StringTable1(){
        makeLogEntry("Destroying StringTable Object");//also added
    }
                    //functions for insertion, erasure, lookup,
                    //etc., but no copy/move/dtor functionality
                     void insert(int i,const std::string&orig)
    {values.insert({i,orig});}
private:
    std::map<int,std::string>values;
    void makeLogEntry(const char*){}
};
class StringTable2{
public:
friend std::ostream& operator<<(std::ostream&os,const StringTable2& orig)
{   for(auto it=orig.values.cbegin();it!=orig.values.cend();it++)
    os<<"First element: "<<it->first<<". Second element:"<<it->second<<'\n';
    return os;}

~StringTable2()
{
    makeLogEntry("Creating StringTable object");//added
    
}
    StringTable2(){
        makeLogEntry("Destroying StringTable Object");//also added
    }
                    //functions for insertion, erasure, lookup,
                    //etc., but no copy/move/dtor functionality
                     void insert(int i,const std::string&orig)
    {values.insert({i,orig});}
    StringTable2(StringTable2&&)=default;
    StringTable2(const StringTable2&)=default;
    StringTable2& operator=(const StringTable2&)=default;
     StringTable2& operator=(StringTable2&&)=default;
private:
    std::map<int,std::string>values;
    void makeLogEntry(const char*){}
};
int main()
{
    StringTable item1,item2;
    item2.insert(13,"str");item2.insert(14,"cpp");
    item1=std::move(item2);
    std::cout<<"synthesized move operations parts:\n";
    std::cout<<__LINE__<<item2<<'\n';

    std::cout<<__LINE__<<item1<<'\n';
     StringTable1 item1_,item2_;
    item2_.insert(13,"str");item2_.insert(14,"cpp");
    item1_=std::move(item2_);
    std::cout<<"User defined destructor will suppress the synthesized move operations: \n";
    std::cout<<__LINE__<<item2_<<'\n';
    std::cout<<__LINE__<<item1_<<'\n';
     StringTable2 item1_1,item2_1;
    item2_1.insert(13,"str");item2_1.insert(14,"cpp");
    item1_1=std::move(item2_1);
    std::cout<<"But, if we set all big five default: \n";
    std::cout<<__LINE__<<item2_1<<'\n';
    std::cout<<__LINE__<<item1_1<<'\n';

}
/*

synthesized move operations parts:
86
88First element: 13. Second element:str
First element: 14. Second element:cpp

User defined destructor will suppress the synthesized move operations: 
93First element: 13. Second element:str
First element: 14. Second element:cpp

94First element: 13. Second element:str
First element: 14. Second element:cpp

But, if we set all big five default: 
99
100First element: 13. Second element:str
First element: 14. Second element:cpp
*/