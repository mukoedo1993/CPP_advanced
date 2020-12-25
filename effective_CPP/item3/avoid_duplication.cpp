#include<iostream>

class TextBlock{
    public:
  TextBlock(const std::string& c):text(c){

  }


const char& operator[](std::size_t position)const
{
    //do bounds checking
    //log access data
    //verify data integrity
    return text[position];
}
char& operator[](std::size_t position)
{
    return 
    const_cast<char&>(          //cast away const on
      static_cast<const TextBlock&>(*this)      //op[]'s return type;
      [position]                                //add const to *this's type;
    );                                           //call const version of op[]
}
private:
   std::string text;
};

int main()
{
        const TextBlock ob1("kkt");
        TextBlock ob2("kab");
        std::cout<<ob1[0]<<' '<<ob2[0]<<'\n';
}