#include <iostream>
using namespace std;

class Cents {
private:
    int m_cents;

public:
    Cents(int cents = 0) { m_cents = cents; }
    int getCents() const { return m_cents; }
    int& getCents() { return m_cents; }

    // ����θ� �ؾ��ϴ� �����ڴ�
    // =, [], (), -> 
    Cents operator+(const Cents& b)
    {
        return Cents(this->m_cents + b.m_cents);
    }
};



int main()
{
    Cents c1(5);
    Cents c2(10);
    //Cents out;

    //add(c1, c2, out);

    cout << (c1 + c2 + Cents(5)+ c2).getCents() << endl;

    return 0;
}