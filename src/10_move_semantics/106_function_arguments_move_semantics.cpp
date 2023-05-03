#include <iostream>
using namespace std;

class Test
{
    string s;
    public:
        // Test(string str):s(std::move(str)){}
        Test(string&& str):s(std::move(str)){}
};

int main()
{
    string name{"Anosh"};
    // Test test(name); // lvalue passed : name is copied in str
                     // str is moved into s
                     // lvalue cannot bind to rvalue ref so Error!
    Test test2(std::move(name));// rvalue passed : name is moved in str
                                // str is moved into s
    return 0;
}