// �����Ҵ�� �޸𸮿� ���� ������ ������ ����ν� �������ִ� class�� ��쿡�¿�
// ���縦 �ϰų� ������ �� �� ��������� ��������� ��� ���迡 ���ؼ�
// ���� ������ �����ε� Ȥ�� ���� ������ ������ �� ��ٷο����ϴ�.
// �� ���� ���ؼ� ���� ������ �帱�ű��� Ȥ�ó� �� �������� ���� �� ��
// �ִµ� �ֱٿ��¿� std::vector, std::string �� library�� ������ ���� 
// ������ ����ϱ� ������ �� ������ ���ؼ� ���� ����ϴ� ���� �����̴ϴ�.
// �ٸ� �̷��� ������ �ݵ�� �����Ѵٴ� �� �ƽð� ������ �ٸ� �� ����Ͻ�
// ���� �� �� �̷��� ������ ����ڰ� �𸣰� ������ٶ�� �� ������
// �˰� ���θ� �Ͻø� �� �� ���� ���θ� �Ͻ� �� ���� �� �����ϴ�.
//
#include <iostream>
#include <cassert>
using namespace std;

class Mystring
{
//private:  // �Ϲ����� �������� private�� �´µ� �ּ��������� public���� �� �� ��. incapsulation���� private�� ���ڵ�.
public:
    char* m_data = nullptr;
    int m_length = 0;

public:
    Mystring(const char* source = "") 
    {
        // assert�� 0�̵Ǹ� ��, false���Ǹ� assert error�� �����Եȴ�.
        assert(source);

        m_length = std::strlen(source) + 1;
        m_data = new char[m_length];

        for (int i = 0; i < m_length; ++i)
            m_data[i] = source[i];

        m_data[m_length - 1] = '\0';
    }

    // �⺻���� ������ copy constructor�� �����Ҵ� �ÿ��� ��������� ���� ���� �� �� �ֱ� ������ ���������.
    Mystring(const Mystring& source) {
        cout << "Copy constructor" << endl;

        m_length = source.m_length;

        if (source.m_data != nullptr) {
            m_data = new char[m_length];

            for (int i = 0; i < m_length; ++i)
                m_data[i] = source.m_data[i];
        }
        else {
            m_data = nullptr;   // 0�� �־ �Ǵµ� ���� ������ nullptr
        }
    }

    Mystring& operator = (const Mystring& source)   // 
    {
        // shallow copy
        /*this->m_data = source.m_data;
        this->m_length = source.m_length;*/

        cout << "Assignment operator " << endl;

        if (this == &source) // prevent self-assignment // (1) ���� 
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

    ~Mystring() {
        delete[] m_data;
    }

    char* getString() { return m_data; }
    int getLength() { return m_length; }
};

int main()
{
    Mystring hello("Hello");

    Mystring str1 = hello;

    Mystring str2;
    str2 = hello;

    Mystring str3(hello);

    // �ڱ� �ڽ��� ���� �� ��
    // hello = hello; // ��� ���忡�� �ð������? ��� �� �� �ִµ� ���α׷� ���忡�� ������ ����(1)

    cout << (int*)hello.m_data << endl; // hello.m_data�� �����ϸ� ���� ���� ������ �ּҰ��� ������ ������ int*�� typecasting�� ��
    cout << hello.getString() << endl;

    {
        Mystring copy = hello;
        cout << (int*)copy.m_data << endl;
        cout << copy.getString() << endl;
    }

    cout << hello.getString() << endl;

    return 0;
}