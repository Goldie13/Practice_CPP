#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*Lambda expression
- Modern c++ / also calles as closures in other languages
- compiler will generate class / functors with unique name chosen by compiler
- function call operator overloaded functor
- it will have same return type as lamda expression
- anonymous & inline
- [] instead of function name
- 
*/
int main()
{
    vector<int> vec{2,4,5,7,8,2,1};
    cout<<"First odd element: "<<*(find_if(vec.begin(), vec.end(),
    [](int n){ return ((n%2)==1);}))<<endl;

    //option 1:
    auto sum = [&]()->int{
        auto x = *(vec.begin()) + 2;
        return x;
    };
    cout<<sum()<<endl;

    //option 2:
    [=]()->void{
        cout<< *(vec.begin()) + 2<<endl;
    }();
    return 0;
}