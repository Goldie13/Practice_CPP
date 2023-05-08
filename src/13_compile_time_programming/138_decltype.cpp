#include <iostream>
using namespace std;
decltype(1+2)y;//it will just consider the type 1+2 will return so int y;

class Test{};
int main()
{
    // auto vs decltype
    // auto: makes var of same type like intialised val
    // decltype: gives type will retain const, ref, etc
    const int cx = 42;
    auto y = cx;// ignored
    cout<<++y<<endl;

    // solved in decltype
    // lval var
    decltype(cx) y1 = 45;

    // gives int&
    int x{1},z{2},f;
    // lavl var
    decltype(x+z) i{y1}; // gives int& lval ref
    // lavl expression
    decltype((f)) j{y}; // gives int& lval ref
    // xvalue expression
    decltype(Test()) n; // give int&& rvalue ref

    //decltype(auto)
    const int& a = 56;
    auto b = a; // ignore const int&
    cout<<++b<<" : allowed"<<endl;
    decltype(auto)c = a;// retained
    // cout<<++c<<endl; //Error! not allowed
    return 0;
}