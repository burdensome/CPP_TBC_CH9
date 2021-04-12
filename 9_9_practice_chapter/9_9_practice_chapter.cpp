#include <iostream>
#include <cassert>

using namespace std;

class Fraction {
private:
    int m_numerator;
    int m_denominator;

    //Fraction(const Fraction& fraction)  // copy constructor
    //    : m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
    //{
    //    cout << "Copy constructor called" << endl;
    //}


public:
    Fraction(int num = 0, int den = 1)
        : m_numerator(num), m_denominator(den)
    {
        cout << "Basic constructor called" << endl;
        assert(den != 0);
    }

    Fraction(const Fraction &fraction)  // copy constructor
        : m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
    {
        cout << "Copy constructor called" << endl;
    }

    friend std::ostream& operator << (std::ostream& out, const Fraction& f)
    {
        cout << f.m_numerator << " / " << f.m_denominator << endl;

        return out;
    }
};

Fraction doSomething() 
{
    Fraction temp(1, 2);
    cout << &temp << endl;
    return temp;
}

int main()
{
    // retur value optimization
    Fraction result = doSomething();
    cout << &result << endl;
    cout << result << endl;
    ////Fraction fr_copy(frac);
    ////Fraction fr_copy = frac;
    //Fraction fr_copy(Fraction(3, 10));  // Fraction(3,10) �� �ʿ䰡 ������ �׳� Fraction(3,10) = (3,10)���� �����Ϸ��� �ٲ����

    //cout << frac << " " << fr_copy << endl;
   /* Fraction frac(3, 5);
    Fraction result = doSomething();
    cout << &result << endl;
    cout << result << endl;*/

    return 0;
}