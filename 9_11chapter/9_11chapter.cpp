// 동적할당된 메모리에 대한 포인터 변수를 멤버로써 가지고있는 class의 경우에는요
// 복사를 하거나 대입을 할 떄 깊은복사냐 얕은복사냐 라는 관계에 의해서
// 대입 연산자 오버로딩 혹은 복사 생성자 구현이 좀 까다로워집니다.
// 그 점에 대해서 제가 설명을 드릴거구요 혹시나 아 어려운가보다 생각 할 수
// 있는데 최근에는요 std::vector, std::string 의 library를 가져다 쓰는 
// 것으로 사용하기 때문에 이 문제에 대해서 직접 고민하는 경우는 없을겁니다.
// 다만 이러한 문제가 반드시 존재한다는 걸 아시고 다음에 다른 언어를 사용하시
// 더라도 이 언어가 이러한 문제를 사용자가 모르게 감춰놨다라는 것 정도는
// 알고 공부를 하시면 좀 더 깊이 공부를 하실 수 있을 것 같습니다.
//
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
        // assert가 0이되면 즉, false가되면 assert error가 나오게된다.
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
        // shallow copy
        /*this->m_data = source.m_data;
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