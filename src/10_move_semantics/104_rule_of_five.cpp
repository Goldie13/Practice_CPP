#include <iostream>
using namespace std;

class Test
{
public:
    // default ctor
    Test() = default;
    /*
    //in effect, copy ctors are declared as deleted
    // Rule 1. copy ctor
    Test(const Test& obj) = delete;

    // Rule 2. copy assignment operator
    Test& operator=(const Test& obj) = delete;
    */

    // Rule 3. move ctor
    Test(Test &&obj) noexcept
    {
        cout << "Move ctor called" << endl;
    }

    // Rule 4. move assignment operator
    Test &operator=(Test &&obj)
    {
        cout << "move assignemnt called" << endl;
        return *this;
    }
    // Rule 5. dtor
    ~Test() noexcept = default;
};

int main()
{
    Test test;                   // defaut ctor
    Test test2(std::move(test)); // move ctor
    test2 = std::move(test);     // move assignment
    // Test test4(test);//Error! why???
    // error: call to implicitly-deleted copy constructor of 'Test'
    return 0;
}