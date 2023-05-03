#include <iostream>
using namespace std;

class Test{};

void g(Test& x)
{ cout<<"modifiable version g() called"<<endl; }

void g(const Test& x)
{ cout<<"immutable version of g() called"<<endl; }

void g(Test&& x) 
{ 
    cout<<"move version of g() called"<<endl; 
}

template<typename T>
void f(T&& x)   //rval instantiation of f(x)
{               // x has name & address so lval
    // g(x);    // lval arg - calls g(Test& x)
                // modifiable version g() called is printed
                // this can be solve by move while calling
    // g(move(x));
    g(std::forward<T>(x));//// std::forward can be to cast to rval
}

int main()
{
    Test x;
    const Test cx;
    cout<<"calling f() with lval arg"<<endl;
    f(x);
    cout<<"calling f() with const lval arg"<<endl;
    f(cx);
    cout<<"calling f() with rval arg"<<endl;
    f(std::move(x));// problem: o/p: modifiable version g() called
    return 0;
}

//output
/*
calling f() with lval arg
modifiable version g() called
calling f() with const lval arg
immutable version of g() called
calling f() with rval arg
modifiable version g() called
*/