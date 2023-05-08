#include <iostream>
using namespace std;

//macros
#define Max(x, y) ( (x) > (y) ? (x) : (y) )

template<class T>
bool get_airthmetic(T) {std::is_arithmetic<T>::value;}

int main()
{
    //macros
    int a{3}, b{3};
    cout<<"a: "<<a<<" & b: "<<b<<endl;
    cout<<"Max(a,b): "<<Max(a, b)<<b<<endl;//replaced by ((a)>(b)?(a):(b))
    cout<<"a: "<<a<<" & b: "<<b<<endl;
    cout<<"Max(a,b): "<<Max(++a, b)<<b<<endl;//replaced by ((++a)>(b)?(++a):(b))
    cout<<"a: "<<a<<" & b: "<<b<<endl;

    //templates
    cout<<" int: "<< boolalpha << get_airthmetic<int> <<endl;
    cout<<" double: "<< boolalpha << get_airthmetic<double> <<endl;
    cout<<" string: "<< boolalpha << get_airthmetic<string> << noboolalpha << endl;
    return 0;
}