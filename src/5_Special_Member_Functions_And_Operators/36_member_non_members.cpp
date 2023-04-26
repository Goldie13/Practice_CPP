#include <iostream>
using namespace std;
/* Member operators overloading to be used
assignemnt =
subscript []
function ()
arrow ->
*/

/* Non member operators overloading to be used
Binary operators
arithmetic operators
equality & relational operators
bitwise operators
>>
<<
*/
class test
{
    string m_name;
    public:
    test(const char* name):m_name(name){}
    test(const string& name):m_name(name){}

    test operator+(const test& test)
    {
        return m_name + test.m_name;
    }

    void print()
    {
        cout<<m_name<<endl;
    }
};

class test2
{
    string m_name;
    int i;
    public:
    test2(const char* name):m_name(name){}
    test2(const string& name):m_name(name){}

    friend test2 operator+(const test2& test1, const test2& test2);

    void print()
    {
        cout<<m_name<<endl;
    }
};

test2 operator+(const test2& test1, const test2& test2)
{
    return test1.m_name + test2.m_name;
}

int main()
{
    test t1{"hello"}, t2{"anosh"};
    test t4 = t1 + t2;
    // test t3 = "hello"s + t2;//not possible as member function but possible as a non member function
    // test t3 = "hello" + t2;//not possible as member function but possible as a non member function
    cout<<"m_name: ";t4.print();

    test2 t5{"ingles"};
    test2 t3 = "hello "+ t5;
    cout<<"t3.m_name: ";t3.print();
    return 0;
}