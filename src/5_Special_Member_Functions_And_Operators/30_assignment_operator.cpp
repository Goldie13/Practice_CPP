/*
- assignment operator is a member function
- invoked whn we assign two objects
- obj y = z;
- members of y will be have same values like z
- takes argument as const reference
- returns modified object: new value of y

- multiple assignments possible ie x = y = z
    - starts from right to left as operator precedence for =
    - so it will be x = (y = z)
    - x will have new value of y
- return is reference but not const
    - as it might require to modify the new object 
    - or store it in container
    - it given const qualifier, then modification wont be possible 
        - compile error
- format: Test& Test::operator=(const Test& other)

- it is passed with hidden pointer this to the object it was called on
- we can modify the object by dereferencing "this" like *this. or this->
- compiler will return object by reference : return *this
    - as "this" will be address of the object
*/
#include <iostream>
using namespace std;
class test
{
    public:
    int i;
    string s;

    /*
    compiler will generate syntheised assignment operator
    test& test::operator=(const test& other)
    {
        this.i = other.i;
        this.i = other.s;
        return *this; //non const reference modified/new object
    }
    */
};

int main()
{
    test test1;
    test test2;
    test1 = test2;//assignment operator
    return 0;
}

