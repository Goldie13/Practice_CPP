/* Copy elison
    - comiler is allowed to call copy ctor in some cases
    - occurs when copying temporary variables during function calls
    - this applies even copy ctor has side effects
    - modern compilers often do copy elision if they can
        - most compiler supply an option to disable it -fno-elide-constructors
*/

#include <iostream>
using namespace std;

class test
{
    public:
    test(){cout<<"default ctor"<<endl;}
    test(const test& other){cout<<"copy ctor"<<endl;}
};

test func()
{
    return test();//default ctor; copy ctor called and stored in return space (stack)
}

void func2(test test)
{
    //do something to test obj
}

int main()
{
    cout<<"calling func"<<endl;
    // test test = func();//copy ctor to return it to test obj
    func2(test()); // temporary is copied thats why copy ctor is called
    cout<<"returned from func"<<endl;

    /* 
    with optimization
    c++ 32_copy_elision.cpp: 
        calling func
        default ctor
        returned from func
    
    without optimization / silent this optimization
    c++ -fno-elide-constructors 32_copy_elision.cpp 
        calling func
        default ctor
        copy ctor
        copy ctor
        returned from func
    */

   //copy elision occurs when obj is passed by value

      
    return 0;
}