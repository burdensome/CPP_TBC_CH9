#include <iostream>
using namespace std;

class Cents {
private:
    int m_cents;

public:
    Cents(int cents) { m_cents = cents; }
    int getCents() const { return m_cents; }
    int& getCents() { return m_cents; }

    friend std::ostream& operator << (std::ostream& out, const Cents& cents) {
        out << cents.m_cents;
        return out;
    }

    Cents operator-()
    {
        return Cents(-m_cents);
    }

    bool operator!()
    {
        return (m_cents == 0 ? true : false);
    }

};

int main()
{
    Cents c1(5);
    Cents c2(0);

    // 단항연산자란? -, ! 이런 것들
    //int a = 3;
    //cout << -a << endl;
    //cout << !a << endl;

    cout << -c1 << endl;
    cout << -c2 << endl;
    cout << -Cents(-10) << endl;


    auto temp = !c1;

    cout << !c1 << " " << !c2 << endl;

    return 0;
}