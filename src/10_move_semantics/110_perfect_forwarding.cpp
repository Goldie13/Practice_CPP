#include <iostream>
using namespace std;

class Test
{
    string m_str;
    public:
        Test(const string& str):m_str(str)
        {
            cout<<"const string& copy ctor"<<endl;
        }
        Test(string&& str):m_str(std::move(str))
        {
            cout<<"string&& move ctor"<<endl;
        }
};

void g(string& x)
{
    cout<<"Modifiable version g called"<<endl;
}

void g(string&& x)
{
    cout<<"Move version of g called"<<endl;
}

template<typename T>
Test make_test(T&& x)
{
    // g(std::forward<T>(x));//uncomment for checking purpose
    return Test(std::forward<T>(x));
}

int main()
{
    string hello{"hello"};

    cout<<"calling make_test with lval arg: "<<endl;
    Test t1 = make_test(hello);
    cout<<"calling make_test with rval arg: "<<endl;
    Test t2 = make_test(std::move(hello));
    cout<<endl;
    return 0;
}

//output
/*
calling make_test with lval arg: 
const string& copy ctor
calling make_test with rval arg: 
string&& move ctor
*/