#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

class Digit {
private:
    int m_digit;

public:
    Digit(int digit = 0) : m_digit(digit){}

    // prefix
    Digit& operator ++ ()
    {
        ++m_digit;
        return *this;
    }

    // postfix : ���� reference return�� ���ϰ� ++ �� �Ķ���Ϳ� int��� dummy���ڸ� �ִ´�. �̰� ���
    Digit operator ++ (int)
    {
        Digit temp(m_digit);

        // �̰� ���� �̷��� �� �ʿ䰡 ���µ� �Ʒ� operator << �� �ؼ� �̷��� �� ���̴�.
        ++(*this);

        return temp;
    }

    friend std::ostream& operator << (std::ostream& out, const Digit& digit) {
        out << digit.m_digit;
        return out;
    }
};

int main()
{
    Digit d(5);

    cout << ++d << endl;
    cout << d << endl;

    cout << d++ << endl;
    cout << d << endl;

    return 0;
}