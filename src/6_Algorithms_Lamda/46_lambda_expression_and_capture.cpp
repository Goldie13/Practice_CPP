/* lambda & variables
has access to non local variables
has access to static variables in the scope
has very limited access to local variables
has access to reference variable & const variables
it can only read but cannot modify const variables / enum which are initialised
compilers often do not implement this  
*/

#include <iostream>
using namespace std;

int global{99};
int main()
{
    int A{23}, B{56};
    static int static_var{34};
    const int const_var{45};
    const int& ref_var{67};

    // auto check = [(){
    // auto check = [ref_var](){
    // auto check = [&]() {//implicit capture of all variables by reference
    //implicit capture of all variables by reference
    auto check = [&]() 
    // auto check = [=, &ref_var]() //implicit capture of all variable by value & 
    //use capture of ref variables using & 
    {
        cout<<global<<endl;
        cout<<static_var<<endl;
        cout<<const_var<<endl;
        cout<<ref_var<<endl;//variable 'ref_var' cannot be implicitly captured in a 
        //lambda with no capture-default specified
        //to solve use variable ref_var as [ref_var] or [&]

        cout<<++static_var<<endl;//error: cannot assign to a variable captured by copy in a non-mutable lambda
        //to solve this add mutable shown above on line 20/21/22
    };

    check();

   
    return 0;
}