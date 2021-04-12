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
    Fraction(char) = delete;

    explicit Fraction(int num = 0, int den = 1)
        : m_numerator(num), m_denominator(den)
    {
        //cout << "Basic constructor called" << endl;
        assert(den != 0);
    }

    Fraction(const Fraction& fraction)  // copy constructor
        : m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
    {
        //cout << "Copy constructor called" << endl;
    }

    friend std::ostream& operator << (std::ostream& out, const Fraction& f)
    {
        cout << f.m_numerator << " / " << f.m_denominator << endl;

        return out;
    }
};

Fraction doSomething(Fraction frac) {
    cout << frac << endl;
    return frac;
}

int main()
{
    Fraction fractest;
    Fraction temp(7);
    //Fraction frac('c');

    doSomething(fractest);
    //doSomething(frac);
   

    return 0;
}