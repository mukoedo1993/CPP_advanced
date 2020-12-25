class Rational{};

const //Many programmers squint when they 
Rational operator*(const Rational&lhs, const Rational&rhs)
{
       return lhs;
}
bool operator==(const Rational&,const Rational&){return true;}
int main(){
            Rational a,b,c;
           // (a*b)=c;//Invoke operator= on the 
            //result of a*b!//error code
//By defining return type of operator* as const, we could prevent the
//possible unwanted assignment.
 


}