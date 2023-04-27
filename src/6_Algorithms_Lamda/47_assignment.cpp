#include <iostream>
using namespace std;

int main()
{
    int x{42}, y{99}, z{0};

    auto lam = [=, &z]() mutable
    { ++x; ++y; z = x + y; };
    lam();
    lam();
    cout<<"x = "<<x<<" y = "<<y<<" z = "<<z<<endl;
    return 0;
}