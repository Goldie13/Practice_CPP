#include <iostream>
using namespace std;

class Test{};

template<typename T>
void function(T&& obj)
{
    cout<<"func called"<<endl;
}

int main()
{
    using Test_ref = Test&;
    Test test;
    ::function<Test&>(test);//compiler instantiates function(Test& obj)
                     //T: test& and obj is T&& ---> Test&
    Test_ref& test_lval{test};
     ::function<Test&>(test_lval);//T is Test& and obj is T&& --> Test&
                           //compiler instantiates function(Test& obj)
    ::function<Test>(std::move(test));//T is Test and obj is T&& ---> Test&&
                                //compiler instantiats function(Test&& obj)
    return 0;
}