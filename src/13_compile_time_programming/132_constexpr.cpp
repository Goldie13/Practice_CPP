#include <iostream>
using namespace std;

static int x = 4;
// constexpr function
constexpr double miles_to_km(double miles)
{
    return miles * 1.602;
}

int main()
{

    // arg is constant expression
    // return is also const expression
    // function is evaluated at compile time
    cout<<"constexpr at compile time: "<<miles_to_km(40)<<endl;

    // arg is not constant expression
    // return is also not constant expression
    // function behaves like normal function & gets executed at runtime
    double arg = 40;
    cout<<"constexpr at run time: "<<miles_to_km(arg)<<endl;

    // both arg & return is not constant expression
    // Error!
    // constexpr double ret = miles_to_km(arg);
    constexpr double ret = miles_to_km(10);

    return 0;
}