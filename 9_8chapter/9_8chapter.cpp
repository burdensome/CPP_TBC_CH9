#include <iostream>
using namespace std;

class Cents {
private:
    int m_cents;

public:
    Cents(int cents = 0) { m_cents = cents; }
    int getCents() const { return m_cents; }
    int& getCents() { return m_cents; }

    operator int() {
        cout << "cast here" << endl;
        return m_cents;
    }
};

void printInt(const int& value) {
    cout << value << endl;
}

class Dollar {
private:
    int m_dollars = 0;

public:
    Dollar(const int& input) : m_dollars(input){}

    operator Cents() {
        return Cents(m_dollars * 100);
    }
};

int main()
{
    // operator type변환 casting연산자는 
    // operator int() 라는 의미는 class Cents의 instance를 아래 방식으로 써도 다 쓸 수 있다 이말?
    // overloading한 typecast 연산자를 사용하고 있음을 의미
    Cents c1(5);
    int value = (int)c1;
    value = int(c1);
    value = static_cast<int>(c1);
   
    printInt(c1);

    Dollar dol(2);

    Cents cents = dol;
    printInt(cents);

    return 0;
}