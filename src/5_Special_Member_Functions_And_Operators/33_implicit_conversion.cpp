#include <iostream>
using namespace std;

class test
{
    int i{42};
    string str;
    public:
    // operator int() const
    // {
    //     return i;
    // }
    // operator bool() const
    // {
    //     return true;
    // }

    //this will give compiler error & will not do implicit conversion
    // explicit operator int() const
    // {
    //     return i;
    // }
    explicit operator bool() const
    {
        return true;
    }
};

//implicit conversion & constructor
class test2
{
    int i;
    public:
    test2(int i) : i(i){}
    test2(const test2& obj){cout<<"copy ctor"<<endl;}
};

int main()
{
    int i = 99;
    /*
    in older c++ version this would compile
    stream have a operator bool() used to check stream
    cin is implicitly converted to bool
    result is then coerced to int
    non overload << operator for int is called
    */
    // cin << i;

    //implicit conversion eg
    test test;
    /*
    Below will not give compiler error
    as compiler will check for int() or bool() operator functions
    it will implicit call this function if its is defined & return the value
    */
    // cout<<test<<endl;

    //below we have cast to int
    // cout<<static_cast<int>(test)<<endl;

    //conditional allowed
    if(test)
        cout<<"This is allowed"<<endl;

    //implicit conversion & constructor
    test2 test2 = 4;
    //above compiler will create temporary obj & call ctor with 4 as argument
    //then call copy ctor: test2 --- temporary obj
    return 0;
}