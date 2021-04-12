// [] subscript operator , ÷�ڿ����� - 
#include <iostream>
#include <cassert>
using namespace std;

class IntList {
private:
    int m_list[10] = { 1,2,3,4,5,6,7,8,9,10 };
    
public:
    int& operator [] (const int index) {
        // if���� ����ؼ� �� �� ������ assert�� �ϴ°� �����ս��� ����
        // �ϴ� [] operator�� ����ϴ� ������ ��û ���� �����͸� ����Ѵٴ� �̾߱��ε�,
        // ���� if���� �������� �ʰ�, assert�� ����Ͽ� ����뵵 �����ϰ�~
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

    //list[3] = 10; // NOK�ǵ��� �ٸ���.
    //(*list)[3] = 10; // OK

    /*
    my_list.setItem(3, 1);
    cout << my_list.getItem(3) << endl;
    my_list.getList()[3] = 1;
    cout << my_list.getList()[3] << endl;*/

    return 0;
}