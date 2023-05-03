#include <iostream>
#include <vector>
#include <exception>
using namespace std;

int main()
{
    try {
        // vector<int> vec;
        // cout << vec.at(2);

        throw 42;
        throw "Something wrong";
    } 
    // catch ( const exception &ex ) { // handles all sub-classes of std::exception
    //     cout << ex.what() << endl;
    // } 
    // catch ( const out_of_range& ex ) {// only handles exceptions of type std::out_of_range
    //     cout << ex.what() << endl;
    // } 
    // catch ( const out_of_range& ex ) {// only handles exceptions of type std::out_of_range
    //     cout << "out of range: "<<ex.what() << endl;
    // } 
    // catch ( const exception &ex ) { // handles all sub-classes of std::exception
    //     cout << ex.what() << endl;
    // } 
    catch(...){
        cout<<"unknown exception: "<<endl;
    }
    return 0;
}