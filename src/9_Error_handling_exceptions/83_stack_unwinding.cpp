#include <iostream>
#include <vector>
using namespace std;

void function()
{
    /*STACK UNWINDING*/
    try {
        vector<int> x;
        x.at(3); // error! it will look for handler
    } catch ( const out_of_range& ex ) { // found one
        cout<<"exception in function() : "<<endl;// print exception
        throw;// rethrow exception
        //no handler found in current scope
    }
    // no handler found in function scope
    // destroy all local vars including exception obj
    // & store in area known to compiler
}

int main()
{
    try{
        function();
        //return of call
        // handler found below
    } catch (const exception& ex) {//found handler
        cout<<"std exception caught in main(): "<<endl;//print exception
    }
    return 0;
}