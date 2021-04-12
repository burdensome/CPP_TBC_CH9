#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

class Digit {
private:
    int m_digit;

public:
    Digit(int digit = 0) : m_digit(digit) {}

    // prefix
    /*int operator ++()
    {
        return ++m_digit;
    }*/
    Digit& operator++()
    {
        
        ++m_digit;
        cout << (int)this << " " << *this << endl;
        // class reference가 return type이고 내 자신의 객체를 리턴한다는 것은 8_7강의(내 정리 : 8_7_1)의
        // 연쇄 호출(chaining member function)과 동일하다. 즉 chaining 한다는 것이다.
        // 근데 막상 prefix 에서 cahining을 할 필요가 있을까? 없다고본다. 
        // 그냥 Digit객체로 리턴하면 되는데 왜 chaining까지 하는지는 모르겠다만.. 
        // 왜냐면 postfix는 어짜피 chain역할이 안되는데 전위 연산자만 되게 할 필요가 있을까?
        return *this;   
    }


    // postfix : 에선 reference return을 안하고 ++ 의 파라미터에 int라는 dummy인자를 넣는다. 이게 약속
    /*int operator ++(int)
    {
        return m_digit++;
    }*/

    Digit operator++(int)
    {
        // temp에다가 m_digit을 넣어 초기화 한다고 생각하면 마음이 편하다
        // 복사 생성자로 하려고하니 헷갈릴 뿐이야. Digit temp = m_digit;
        Digit temp(m_digit);
        ++m_digit;
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

    //cout << (int)&d << " " << d << endl;
    
    cout << ++d << endl;
    cout << ++d << endl;
    cout << d << endl;

    cout << d++ << endl;
    cout << d << endl;

    return 0;
}