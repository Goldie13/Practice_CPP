/* Immovable class:
    - we can make class immovable and uncopyable
        - obj of this class cannot be passed to a function
        - obj of this class cannot be returned by a function
        - eg low level concurrency objects which release lock at the end of their scope
    - to do this, delete the copy operators
        - compiler will not synthesize the move operators
        - any copy or move operation will invoke copy operators which are deleted
*/

#include <iostream>
using namespace std;

class Test
{
    public:
        // default ctor
        Test() = default;

        //copy ctor are declared as deleted
        //copy ctor
        Test(const Test& obj) = delete;

        //copy assignment operator
        Test& operator=(const Test& obj) = delete;

        /*
        //compiler will not generate any move operators
        */
};

int main()
{
    Test test;//default 
    // Test test2(test);//Error! calling deleted copy ctor
    // Test test3 = test;//Error! calling deleted assignment operator
    // Test test4(std::move(test));//move ctor is deleted
    // Test test5 = std::move(test);//move assignment is deleted
    return 0;
}