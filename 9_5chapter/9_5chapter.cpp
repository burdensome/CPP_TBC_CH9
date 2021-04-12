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

    // postfix : 에선 reference return을 안하고 ++ 의 파라미터에 int라는 dummy인자를 넣는다. 이게 약속
    Digit operator ++ (int)
    {
        Digit temp(m_digit);

        // 이건 굳이 이렇게 할 필요가 없는데 아래 operator << 를 해서 이렇게 한 것이다.
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