// 기본적인 자료형은 연산자들이 다 정의되어있어 그냥 되는데
// class같이 사용자 자료형도 산술연산자를 정의할 수 있음 
//산술연산자 오버로딩
#include <iostream>
using namespace std;

class Cents {
private:
    int m_cents;

public:
    Cents(int cents = 0) { m_cents = cents; }
    int getCents() const { return m_cents; }
    int& getCents() { return  m_cents; }

    //(4) friend로 안에 넣을 수도 있다.
    //friend Cents operator + (const Cents& c1, const Cents& c2);

    //(5) friend로 하면서 동시에 함수를 그냥 넣어버릴 수 있다.
    //friend Cents operator + (const Cents& c1, const Cents& c2) {
    //    return Cents(c1.getCents() + c2.getCents());
    //}

    //(6) friend를 빼서 멤버function으로 정의하는 방법
    Cents operator + (const Cents& c2) {
        return Cents(this->m_cents + c2.m_cents);
    }

    //(6) 멤버function으로만 정의가 가능한 것은 =, [], (), ->
};

// (1)옛날 스타일
//void add(const Cents& c1, const Cents& c2, Cents& c_out) {
//    c_out.getCents() = c1.getCents() + c2.getCents();
//}

// (2)최근 스타일로 return타입으로 class를 리턴
//Cents add(const Cents& c1, const Cents& c2) {
//    return Cents(c1.getCents() + c2.getCents());
//}

// (3)최근 스타일에서 연산자 오버로딩을 접목하면?
//Cents operator + (const Cents& c1, const Cents& c2) {
//    return Cents(c1.getCents() + c2.getCents());
//}

int main()
{
    Cents cents1(6);
    Cents cents2(8);
    
    //(1)옛날방식
   /* Cents sum;
    add(cents1, cents2, sum);
    cout << sum.getCents() << endl;*/

    //(2)최근 스타일
    //cout << add(cents1, cents2).getCents() << endl;

    //(3)최근 스타일에서 연산자 오버로딩을 접목하면?
    //cout << (cents1 + cents2 + Cents(6)).getCents << endl;

    //(4), (5) 
    cout << (cents1 + cents2 + Cents(6) + Cents(10) + Cents(10) + Cents(100)).getCents() << endl;

    // 연산자 오버로딩이 안되는 것들
    // ?: conditional operator(3항연산자) 는 overloading이 안됨, 
    // ::(범위연산자) ,
    // sizeof, 
    // . (member selection), 
    // .* (member pointer selection)

    // ^ 연산자는 연산자 오버로딩이 되긴 하나 연산자 우선순위가 너무 낮아서 괄호를 써서 사용 할 순 있으나
    // 그냥 사용을 안하는 것이 좋다.

    return 0;
}