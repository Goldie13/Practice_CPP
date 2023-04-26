#include <iostream>
using namespace std;

class test
{
    int i{42};
    string s{"Hello"};
    public:
    friend void print(const test& test); //friend function
    friend class example;//friend class
};

class example
{
    public: 
    void print(const test& test)
    {
        cout<<"test.i : "<<test.i<<" test.s : "<<test.s<<endl;
    }
};

void print(const test& test)
{
    cout<<"test.i : "<<test.i<<" test.s : "<<test.s<<endl;
}

int main()
{
    test test;
    print(test);

    example eg;
    print(test);
}
