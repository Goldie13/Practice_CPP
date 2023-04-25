#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

void func1(int y)
{
    cout << y << endl;
}

int func2(int* y)
{
    *y = 3;
    return *y;
}

int func3(int& z)
{
    return ++z;
}

int func4(const int& z)
{
    //error: increment of read-only reference ‘z’
    //comment it
    //z++;
    return z;
}

int main()
{
    //PassbyValue
    int x;
    x = 2;
    func1(x);
    
    //PassByAddress
    cout << "Before passing to function by address: x : " << x << endl;
    int y = func2(&x);
    cout << "After passing to function by address: x : " << y << endl;
    
    //PassByReference
    int b = func3(x);
    cout << "After passing to function by PassByReference: x : " << b << endl;
    
    //PassbyconstantReference
    int c = func4(x);
    cout << "After passing to function by PassByConstReference: x : " << c << endl;
    
    return 0;
}