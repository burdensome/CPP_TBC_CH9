// �⺻���� �ڷ����� �����ڵ��� �� ���ǵǾ��־� �׳� �Ǵµ�
// class���� ����� �ڷ����� ��������ڸ� ������ �� ���� 
//��������� �����ε�
#include <iostream>
using namespace std;

class Cents {
private:
    int m_cents;

public:
    Cents(int cents = 0) { m_cents = cents; }
    int getCents() const { return m_cents; }
    int& getCents() { return  m_cents; }

    //(4) friend�� �ȿ� ���� ���� �ִ�.
    //friend Cents operator + (const Cents& c1, const Cents& c2);

    //(5) friend�� �ϸ鼭 ���ÿ� �Լ��� �׳� �־���� �� �ִ�.
    //friend Cents operator + (const Cents& c1, const Cents& c2) {
    //    return Cents(c1.getCents() + c2.getCents());
    //}

    //(6) friend�� ���� ���function���� �����ϴ� ���
    Cents operator + (const Cents& c2) {
        return Cents(this->m_cents + c2.m_cents);
    }

    //(6) ���function���θ� ���ǰ� ������ ���� =, [], (), ->
};

// (1)���� ��Ÿ��
//void add(const Cents& c1, const Cents& c2, Cents& c_out) {
//    c_out.getCents() = c1.getCents() + c2.getCents();
//}

// (2)�ֱ� ��Ÿ�Ϸ� returnŸ������ class�� ����
//Cents add(const Cents& c1, const Cents& c2) {
//    return Cents(c1.getCents() + c2.getCents());
//}

// (3)�ֱ� ��Ÿ�Ͽ��� ������ �����ε��� �����ϸ�?
//Cents operator + (const Cents& c1, const Cents& c2) {
//    return Cents(c1.getCents() + c2.getCents());
//}

int main()
{
    Cents cents1(6);
    Cents cents2(8);
    
    //(1)�������
   /* Cents sum;
    add(cents1, cents2, sum);
    cout << sum.getCents() << endl;*/

    //(2)�ֱ� ��Ÿ��
    //cout << add(cents1, cents2).getCents() << endl;

    //(3)�ֱ� ��Ÿ�Ͽ��� ������ �����ε��� �����ϸ�?
    //cout << (cents1 + cents2 + Cents(6)).getCents << endl;

    //(4), (5) 
    cout << (cents1 + cents2 + Cents(6) + Cents(10) + Cents(10) + Cents(100)).getCents() << endl;

    // ������ �����ε��� �ȵǴ� �͵�
    // ?: conditional operator(3�׿�����) �� overloading�� �ȵ�, 
    // ::(����������) ,
    // sizeof, 
    // . (member selection), 
    // .* (member pointer selection)

    // ^ �����ڴ� ������ �����ε��� �Ǳ� �ϳ� ������ �켱������ �ʹ� ���Ƽ� ��ȣ�� �Ἥ ��� �� �� ������
    // �׳� ����� ���ϴ� ���� ����.

    return 0;
}