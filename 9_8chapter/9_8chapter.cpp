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
    // operator type��ȯ casting�����ڴ� 
    // operator int() ��� �ǹ̴� class Cents�� instance�� �Ʒ� ������� �ᵵ �� �� �� �ִ� �̸�?
    // overloading�� typecast �����ڸ� ����ϰ� ������ �ǹ�
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