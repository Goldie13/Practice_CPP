/* 
specialised version of constructor
it takes only one argument ie object of the class
it uses existing object of class to initialise other object
argument is passed by reference
Test(const Test& other);
*/
#include <iostream>
using namespace std;
class test
{
    public:
    test(){ cout << "Ctor" << endl;}
    ~test(){ cout << "Dtor" << endl;}
    test(const test& other) { cout << "copy Ctor" << endl;}
};

class test2
{
    public:
    int i;
    string s;

    /*
    compiler will create synthesized copy constructor for us
    for all data members
    test2(const test2& other) : i(other.i), s(other.s) {}
    */
};
int main()
{
    test test_obj{};                    //Ctor
    test test_obj_2{test_obj};          //copy Ctor
    test test_obj_3 = test_obj_2;       //copy Ctor as new obj is created with existing object then copy ctor is called
    test_obj = test_obj_3;              //overload default copy assignment
                                        //Dtor for test_obj_3
                                        //Dtor for test_obj_2
                                        //Dtor for test_obj
                                        
}