#include <iostream>
#include <cassert>
#include <initializer_list>

using namespace std;

class IntArray
{
private:
    unsigned m_length = 0;
    int* m_data = nullptr;

public:
    IntArray(const unsigned length)
        : m_length(length)
    {
        m_data = new int[m_length];
    }

    IntArray(const std::initializer_list<int>& list)
        : IntArray(list.size())
    {
        int count = 0;
        for (auto& element : list)
        {
            m_data[count] = element;
            ++count;
        }
    }



    /*IntArray(unsigned length)
        : m_length(length)
    {
        m_data = new int[length];
    }*/

    //IntArray(const std::initializer_list<int>& list)
    //    : IntArray(list.size())
    //{
    //    int count = 0;
    //    for (auto& element : list)
    //    {
    //        m_data[count] = element;
    //        ++count;
    //    }

    //    //for (unsigned count = 0; count < lise.size(); ++count)
    //    //    m_data[count] = list[count]; // error
    //    // initializer list는 위와 같이 list[count] 같은 것을 허락해주지않음.
    //}

    ~IntArray()
    {
        delete[] this->m_data;
    }

    // TODO : overload operator =

    friend ostream& operator << (ostream& out, IntArray& arr)
    {
        for (unsigned i = 0; i < arr.m_length; ++i) {
            out << arr.m_data[i] << " ";
        }
        out << endl;
        return out;
    }
};


int main()
{
    int my_arr1[5] = { 1, 2, 3 ,4 ,5 };
    int* my_arr2 = new int[5]{ 1,2,3,4,5 };

    auto il = { 10, 20 , 30 };

    IntArray int_array{ 1,2,3,4,5,6,7,8,9,0 };
    cout << int_array << endl;

    return 0;
}