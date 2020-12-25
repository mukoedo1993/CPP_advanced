#include<iostream>

class TextBlock{
    public:
    TextBlock(const std::string&orig):text(orig){}
    const char& operator[](std::size_t position)const {         //operator[] for
        return text[position];}                             //const objects

    char& operator[](std::size_t position){                  //operator[] for
        return text[position];                              //non-const objects

       
    }
    
   private:
   std::string text;
};


class TextBlock1{
    public:
    TextBlock1(const std::string&orig):text(orig){}
    const char& operator[](std::size_t position)const {         //operator[] for
        return text[position];}                             //const objects

    char operator[](std::size_t position){                  //operator[] for
        return text[position];                              //non-const objects

       
    }
    
   private:
   std::string text;
};

int main(){
            TextBlock tb("Hello");
            std::cout<<tb[0];               //calls non-const
                                          //TextBlock::operator[]
          tb[0]='x';                //fine - writing a non-const TextBlock

        //By overloading operator[] and giving the different versions different return 
        //types, you can have const and non-const TextBlocks handled differently.
      const TextBlock ctb("Hello");
      std::cout<<ctb[0];                //calls const TextBlock::operator[]

     TextBlock1 tb_("Hello");
    // tb_[0]='k';// error: lvalue required as left operand of assignment
}