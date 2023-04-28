#include <iostream>
#include <random>
using namespace std;

int main()
{
    random_device rd;
    // mt19937 mt(); // create engine object - to generate sequence

    //or

    mt19937 mt(rd()); //recommended

    uniform_int_distribution<int> idist(0, 10);
    cout << "Int between 0 & 10: " << endl;
    for (auto i = 0; i < 5; ++i)
    {
        cout << idist(mt) << " ";
    }
    cout << endl;

    uniform_real_distribution<double> fdist(0, 10);
    cout << "double between 0 & 10: " << endl;
    for (auto i = 0; i < 5; ++i)
    {
        cout << fdist(mt) << endl;
    }
    cout << endl;

    /* random_device
    - these are HW generated random nos from system entropy data
    - it will produce PRNR if:
        - system doesnot provide entropy data
        - compiler is GNU C++ which does not support Entropy data
    - if all entropy data is used up
        - it will stop & wait untill more data becomes available
    - random_device is much slower than mt19937 but is cypto secure if fully implemented
    - random_device is also implemented as a functor
        - random_device rd
    - because performance rd is not suitable to generate random nos
    - it is often used to generate seeds mt19937(rd());
    */

    /* Recommendations:
    - use mt19937 as random number engine 
    - make engine & distribution objects static
        - creating them is fairly time consuming
        - every time an engine is intialised sequence starts again
        - usually we will need one object per program 
    */
    
    return 0;
}