#include <iostream>
#include <fstream>
using namespace std;

class Point {
private:
    double m_x, m_y, m_z;

public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0)
        : m_x(x), m_y(y), m_z(z)
    {}

    double getX() { return m_x; }
    double getY() { return m_y; }
    double getZ() { return m_z; }

    //void print()
    //{
    //    cout << m_x << " " << m_y << " " << m_z;
    //}

    friend std::ostream& operator << (std::ostream& out, const Point& point)
    {
        out << point.m_x << " " << point.m_y << " " << point.m_z;

        return out;
    }

    friend std::istream& operator >> (std::istream& in, Point& point)
    {
        in >> point.m_x >> point.m_y >> point.m_z;

        return in;
    }
};



int main()
{
    ofstream of("out.txt");
    //Point a(1.0, 2.0, 3.0), b(4.0, 5.0, 6.0);
    Point a, b;

    cin >> a >> b;

    //cout << a.getX() << " " << a.getY() << " " << a.getZ() << endl;

    //a.print();
    //b.print();

    cout << a << " " << b << endl;
    of << a << " " << b << endl;

    of.close();

    return 0;
}