// [] subscript operator , 첨자연산자 - 
#include <iostream>
#include <cassert>
using namespace std;

class IntList {
private:
    int m_list[10] = { 1,2,3,4,5,6,7,8,9,10 };

public:
    /*void setItem(int index, int value) {
        m_list[index] = value;
    }

    int getItem(int index) {
        return m_list[index];
    }

    int* getList()
    {
        return m_list;
    }*/

    // 주소를 갖고있는 l-value여야 하니까 레퍼런스를 리턴한다!!!!!
    int& operator[] (const int index)
    {
        assert(index >= 0);
        assert(index < 10);

        return m_list[index];
    }

    const int& operator[] (const int index) const
    {
        assert(index >= 0);
        assert(index < 10);

        return m_list[index];
    }
};

int main()
{
   /* IntList my_list;
    my_list.setItem(3, 1);
    cout << my_list.getItem(3) << endl;
    *(my_list.getList() + 3) = 10;
    cout << my_list.getItem(3) << endl;
    my_list.getList()[3] = 15;
    cout << my_list.getItem(3) << endl;*/


    //const IntList my_list;
    ////my_list[3] = 10;
    ////my_list[3] = 10;
    //cout << my_list[5] << endl;

    IntList* list = new IntList;

    list[3] = 10;

    (*list)[3] = 10;

    return 0;
}