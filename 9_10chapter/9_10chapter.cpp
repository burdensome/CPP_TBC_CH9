// 프로그래머의 편의를 돕기 위해서 생성자를 변환을 시켜주는
// converting constructor에 대해서 설명을 드리구요
// 이 변환 생성자를 사용하지 못하게하는 explicit키워드에 대해서 설명을 드리겠습니다.
// 그리고 특정한 생성자를 사용을 하지 못하게 지워버리는 말그대로 지워버리는 
// delete키워드에 대해서도 설명을 드리겠습니다.
// 동적할당에서 메모리를 지울 때 사용했던 delete과는 다른 이야기이니까
// 참고하시기 바랍니다.
//

#include <iostream>
#include <cassert>

using namespace std;

class Fraction {
private:
    int m_numerator;
    int m_denominator;

    //Fraction(const Fraction& fraction)  // copy constructor
    //    : m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
    //{
    //    cout << "Copy constructor called" << endl;
    //}


public:
    Fraction(char) = delete;
    
    explicit Fraction(int num = 0, int den = 1)
        : m_numerator(num), m_denominator(den)
    {
        //cout << "Basic constructor called" << endl;
        assert(den != 0);
    }

    Fraction(const Fraction &fraction)  // copy constructor
        : m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
    {
        //cout << "Copy constructor called" << endl;
    }

    friend std::ostream& operator << (std::ostream& out, const Fraction& f)
    {
        cout << f.m_numerator << " / " << f.m_denominator << endl;

        return out;
    }
};

Fraction doSomething(Fraction frac) {
    cout << frac << endl;
    return frac;
}

int main()
{
    Fraction temp(7);
    Fraction frac('c');

    doSomething(temp);
    doSomething(Fraction(8));
    doSomething(9);

    return 0;
}