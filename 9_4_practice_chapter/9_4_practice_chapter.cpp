#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

class Cents {
private:
    int m_cents;

public:
    Cents(int cents = 0) { m_cents = cents; }
    int getCents() const { return m_cents; }
    int& getCents() { return m_cents; }

    // operator > 는 안됨 operator < 로만 쓸 수 있음.
    /*friend bool operator < (const Cents& c1, const Cents& c2) {
        return c1.m_cents < c2.m_cents;
    }*/

    friend std::ostream& operator << (std::ostream& out, const Cents& cents) {
        out << cents.m_cents;
        return out;
    }

    Cents operator - () const {
        return Cents(-m_cents);
    }
    // 여기부터~
    bool operator ! () const {
        return (m_cents == 0) ? true : false;
    }

    bool operator == (const Cents& c2) {
        return this->m_cents == c2.m_cents;
    }

    bool operator != (const Cents& c2) {
        return this->m_cents != c2.m_cents;
    }

    bool operator < (const Cents& c2)
    {
        return (this->m_cents < c2.m_cents ? true : false);
    }
      
};

int main()
{
    /*Cents c1(5);
    Cents c2(5);

    if (c1 == c2)
        cout << "Equal " << endl;

    if (c1 != c2)
        cout << "Not Equal " << endl;

    cout << !c1 << " " << !c2 << endl;*/


    vector<Cents> arr(20);
    for (unsigned i = 0; i < 20; ++i)
        arr[i].getCents() = i;

    std::random_shuffle(begin(arr), end(arr));

    for (auto& e : arr)
        cout << e << " ";
    cout << endl;

    std::sort(begin(arr), end(arr));

    for (auto& e : arr)
        cout << e << " ";
    cout << endl;


    return 0;
}