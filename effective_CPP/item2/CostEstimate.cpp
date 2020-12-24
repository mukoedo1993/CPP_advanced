#include<iostream>
#include<vector>
class CostEstimat{
    private:
    static const double FudgeFactor;
};
const double CostEstimat::FudgeFactor=1.35;

class CostEstimat1{
    private:
    //static const double FudgeFactor=1.35;
    //‘constexpr’ needed for in-class initialization of static data member ‘const double CostEstimat1::FudgeFactor’ 
    //of non-integral type [-fpermissive]
};

int main()
{
    CostEstimat ob1;
    CostEstimat1 ob2;
}