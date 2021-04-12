// [] subscript operator , 첨자연산자 - 
#include <iostream>
#include <cassert>
using namespace std;

class IntList {
private:
    int m_list[10] = { 1,2,3,4,5,6,7,8,9,10 };
    
public:
    int& operator [] (const int index) {
        // if문을 사용해서 할 수 있지만 assert로 하는게 퍼포먼스가 좋고
        // 일단 [] operator를 사용하는 이유가 엄청 많은 데이터를 사용한다는 이야기인데,
        // 보통 if문은 권장하지 않고, assert를 사용하여 디버깅도 좋게하고~
        assert(index >= 0);
        assert(index < 10);

        return m_list[index];
    }

    const int& operator [] (const int index) const{
        assert(index >= 0);
        assert(index < 10);

        return m_list[index];
    }

    //void setItem(int index, int value) {
    //    m_list[index] = value;
    //}

    //int getItem(int index) {
    //    return m_list[index];
    //}

    //int* getList() {
    //    return m_list;
    //}
};

int main()
{
    IntList my_list;
    my_list[3] = 10;
    cout << my_list[3] << endl;

    IntList* list = new InitList;

    //list[3] = 10; // NOK의도가 다르다.
    //(*list)[3] = 10; // OK

    /*
    my_list.setItem(3, 1);
    cout << my_list.getItem(3) << endl;
    my_list.getList()[3] = 1;
    cout << my_list.getList()[3] << endl;*/

    return 0;
}