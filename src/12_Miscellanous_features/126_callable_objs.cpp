#include <iostream>
#include <functional>
using namespace std;

/*
- std::function in <functional>
- this can be any callable obj which has given signature
- template clas
    - obj signature is the parameter
    - function<bool(const string&)> match_ptr;
- implemented using inheritance

*/
class Test{
    public:
    void func(int x, const string& s)
    {
        cout<<" func called with arguments "
        <<x<<" and "<<s<<endl;
    }
};

int main()
{
    //define pfunc as a ptr to a member function of test
    auto pfunc = &Test::func;

    //generate a callable obj from pds
    auto f = mem_fn(pfunc);

    //invoke this callable obj
    Test test;
    f(test, 3, "callableObject");

    return 0;
}