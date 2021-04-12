#include <iostream>
using namespace std;

class Accumulator
{
private:
    int m_counter = 0;

public:
    int operator()(int i) { return (m_counter += i); }
};

int main()
{
    Accumulator acc;
    // 마치 함수를 호출 하는 것 같은 형태를 나타내는데
    // functor라고 불리운다
    cout << acc(10) << endl;
    cout << acc(20) << endl;

    return 0;
}