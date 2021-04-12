#include <iostream>
#include <cassert>
using namespace std;

class Mystring
{
    //private:  // 일반적인 구현에선 private가 맞는데 주소찍으려고 public으로 한 것 뿐. incapsulation에는 private이 좋겠따.
public:
    char* m_data = nullptr;
    int m_length = 0;

public:
    Mystring(const char* source = "") 
    {
        cout << "Default constructor" << endl;
        assert(source);

        m_length = std::strlen(source) + 1;
        m_data = new char[m_length];

        for (int i = 0; i < m_length; ++i)
            m_data[i] = source[i];

        m_data[m_length - 1] = '\0';
    }

    // 기본으로 생성된 copy constructor가 동적할당 시에는 복사생성자 사용시 위험 할 수 있기 떄문에 직접만든다.
    Mystring(const Mystring& source) {
        cout << "Copy constructor" << endl;

        m_length = source.m_length;

        if (source.m_data != nullptr) {
            m_data = new char[m_length];

            for (int i = 0; i < m_length; ++i)
                m_data[i] = source.m_data[i];
        }
        else {
            m_data = nullptr;   // 0을 넣어도 되는데 요즘 문법인 nullptr
        }
    }

    Mystring& operator = (const Mystring& source)   // 
    {
        //shallow copy
        /*cout << "Default copy constructor " << endl;
        this->m_data = source.m_data;
        this->m_length = source.m_length;*/

        cout << "Assignment operator " << endl;

        if (this == &source) // prevent self-assignment // (1) 여기 
            return *this;

        delete[] m_data;

        m_length = source.m_length;

        if (source.m_data != nullptr) {
            m_data = new char[m_length];

            for (int i = 0; i < m_length; ++i)
                m_data[i] = source.m_data[i];
        }
        else {
            m_data = nullptr;
        }
    }

    ~Mystring() 
    {
        //cout << "소멸자" << endl;
        delete[] m_data;
    }

    char* getString() { return m_data; }
    int getLength() { return m_length; }
};

int main()
{
    Mystring hello("Hello");

    // 자기 자신을 대입 할 떄
    // hello = hello; // 사람 입장에선 시간낭비네? 라고 할 수 있는데 프로그램 입장에선 문제가 생김(1)

    cout << (int*)hello.m_data << endl; // hello.m_data를 실행하면 문자 값이 나오니 주소값을 보려고 강제로 int*로 typecasting을 함
    cout << hello.getString() << endl;

    {
        Mystring copy = hello;
        cout << (int*)copy.m_data << endl;
        cout << copy.getString() << endl;
    }

    cout << hello.getString() << endl;

    return 0;
}