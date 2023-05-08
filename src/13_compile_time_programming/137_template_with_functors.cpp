#include <iostream>
#include <functional>
using namespace std;

template<typename T, typename Func = less<T>>
bool compare(T t1, T t2, Func f = Func())
{
    return f(t1,t2);
}

int main()
{
    int x{2}, y{4};
    cout<<"x: "<<x<<" y: "<<y<<endl;

    auto b = compare(x, y, [](int i, int j){
        return i < j;
    });
    cout<<"result of calling compare with lambda: "
    << b <<endl;

    cout<<"result of calling compare with lambda: "
    << compare(x,y) <<endl;
    return 0;
}