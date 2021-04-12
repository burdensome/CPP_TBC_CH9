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
        // class reference�� return type�̰� �� �ڽ��� ��ü�� �����Ѵٴ� ���� 8_7����(�� ���� : 8_7_1)��
        // ���� ȣ��(chaining member function)�� �����ϴ�. �� chaining �Ѵٴ� ���̴�.
        // �ٵ� ���� prefix ���� cahining�� �� �ʿ䰡 ������? ���ٰ���. 
        // �׳� Digit��ü�� �����ϸ� �Ǵµ� �� chaining���� �ϴ����� �𸣰ڴٸ�.. 
        // �ֳĸ� postfix�� ��¥�� chain������ �ȵǴµ� ���� �����ڸ� �ǰ� �� �ʿ䰡 ������?
        return *this;   
    }


    // postfix : ���� reference return�� ���ϰ� ++ �� �Ķ���Ϳ� int��� dummy���ڸ� �ִ´�. �̰� ���
    /*int operator ++(int)
    {
        return m_digit++;
    }*/

    Digit operator++(int)
    {
        // temp���ٰ� m_digit�� �־� �ʱ�ȭ �Ѵٰ� �����ϸ� ������ ���ϴ�
        // ���� �����ڷ� �Ϸ����ϴ� �򰥸� ���̾�. Digit temp = m_digit;
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