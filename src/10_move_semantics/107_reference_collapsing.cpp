#include <iostream>
using namespace std;

void func(int& j)
{
    cout<<"func called with argument int&"<<endl;
}

int main()
{
    using int_ref = int&;
    int i{4};
    int_ref& j{i};//ref to i
    int_ref& rj{j};//ref to (ref to int i) collapses to (ref to i)
    func(rj);
    return 0;
}