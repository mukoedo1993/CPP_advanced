#include<iostream>
#include<memory>
//Page 33:
//I made this elabrote example to show that we could reach bitwise constness
// even if the logical constness is violated.
class CTextBlock{
    public:
    friend class std::shared_ptr<char>;
    
    CTextBlock(char c){
        pText=new char(c);
    }
    char& operator[] (std::size_t position)const        //inappropritate (but bitwise)
    {return pText[position];}                            //const declaration of operator[]

private:
       char* pText;
 public:   
        ~CTextBlock();
       
};
CTextBlock::~CTextBlock()
{
    delete pText;
    pText=nullptr;
}
int main()
{
    const CTextBlock cctb('t');         //declare constant object
    char *pc=&cctb[0];                      //call the const operator[] to get a pointer
                                            //to cctb's data
    std::cout<<*pc<<std::endl;  //t
     *pc='k';

    std::cout<<*pc<<std::endl;   //k                                
}