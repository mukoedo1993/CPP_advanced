//void is counted as a literal type in C++14, but not in C++11
class Point{
    public:
    constexpr Point(double xVal=0,double yVal=0)noexcept
    :x(xVal),y(yVal)
    {}

    constexpr double xValue()const noexcept{return x;}
    constexpr double yValue()const noexcept{return y;}
    constexpr void setX(double newX)noexcept{x=newX;}
     constexpr void setY(double newY)noexcept{y=newY;}
    private:
    double x,y;
};
//return reflection of p w.r.t the origin(C++14)
constexpr Point reflection(const Point&p)noexcept
{
    Point result;
    result.setX(-p.xValue());
    result.setX(-p.yValue());

    return result;
}

constexpr
Point midpoint(const Point&p1,const Point&p2)noexcept
{
    return {
        (p1.xValue()+p2.xValue())/2,
          (p1.yValue(),p2.yValue())/2
    };
}

int main()
{
    constexpr Point p1(9.4,27.7);//OK
    constexpr Point p2(28.8,5.3);//OK
    constexpr auto mid=midpoint(p1,p2);//OK
}