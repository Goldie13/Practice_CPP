#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    //scientific
    double pi = 3.14567890;
    cout<<scientific<<pi<<endl;
    cout<<scientific<<uppercase<<pi<<endl;

    //fixed
    double c{299'792'458};//by default 6 digits
    cout<<fixed<<c<<endl;
    double e{1.6235e-19};
    cout<<fixed<<e<<endl;//by default 6 digits

    //precision
    //floating point precision determines the number of digits
    //for default float & fixed formats, default precision is 6
    double pi2 = 3.142678;
    cout<<setprecision(2)<<pi2<<endl;

    return 0;
}   