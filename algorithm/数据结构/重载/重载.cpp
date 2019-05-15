#include<iostream>
#include<fstream>
using namespace std;
class Point
{
public:
    Point();
    Point(int x,int y);
    Point(Point& p);
    ~Point();
    int get_x();
    int get_y();
    void set_x(int a);
    void set_y(int b);
    Point operator+(Point p);
    Point operator*(int i);
    int operator>(Point p);
    int operator<(Point p);
    int operator==(Point& p);
private:
    int x;
    int y;
    friend istream& operator>>(istream& in,Point& p);
    friend ostream& operator<<(ostream& out,Point& p);
};
Point::Point()
{
    this->x=0;
    this->y=0;
}
Point::Point(int x,int y):x(x),y(y) {};
Point::Point(Point& p):x(p.x),y(p.y) {};
Point::~Point() {}
int Point::get_x()
{
    return this->x;
}
int Point::get_y()
{
    return this->y;
}
void Point::set_x(int x)
{
    this->x=x;
}
void Point::set_y(int y)
{
    this->y=y;
}
Point Point::operator+(Point p)
{
    this->x=this->x+p.x;
    this->y=this->y+p.y;
    return *this;
}
Point Point::operator*(int i)
{
    this->x=this->x*i;
    this->y=this->y*i;
    return *this;
}
int Point::operator>(Point p)
{
    return this->x>p.x && this->y>p.y;
}
int Point::operator<(Point p)
{
    return this->x<p.x && this->y<p.y;
}
int Point::operator==(Point& p)
{
    return this->x==p.x && this->y==p.y;
}
istream& operator>>(istream& in,Point& p)
{
    in>>p.x>>p.y;
    return in;
}
ostream& operator<<(ostream& out,Point& p)
{
    out<<p.get_x()<<" "<<p.get_y()<<endl;
    return out;
}
int main()
{
    Point p1(3,5);
    Point p4(6,7);
    cout<<p1.get_x()<<" "<<p1.get_y()<<endl;
    cout<<p1;
    Point p2;
    p2=p1*10;
    cout<<p2;
    Point p3;
    p3=p1+p4;
    cout<<p3;
    int i;
    i=p1>p2;
    cout<<i;

    return 0;
}





