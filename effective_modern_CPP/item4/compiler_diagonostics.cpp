template<class T>
class TD;//declaration only for TD

int main(){
    const int theAnswer=42;
auto x=theAnswer;
auto y=theAnswer;
    //TD<decltype(x)>xType;//aggregate ‘TD<int> xType’ has incomplete type and cannot be defined
    //incomplete type is not allowed
    //TD<decltype(y)>yType;//aggregate ‘TD<int> yType’ has incomplete type and cannot be defined
    //incomplete type is not allowed
}