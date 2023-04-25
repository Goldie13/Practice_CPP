/*
most stream manipulators in <iostream>
manipulators which take arguments are in <iomanip>
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
    int x = 2;
    bool is_negative = x<0;

    cout<<"the value of is_negative: "<<is_negative<<endl;
    cout<<"is_negative is: "<<boolalpha<<is_negative<<endl;
    cout<<" x == 2 is:  "<<(x == 2)<<endl;
    cout<<"the numeric of \"false\" is: "<<noboolalpha<<false<<endl;
    cout<<" x == 2 is:  "<<(x == 2)<<endl;

    //by default output stream doesnot manipulate the data
    // it is presented as it is

    //setw():
    //it will pad up output to make the width of its argument
    //it affects next data item on the stream
    //defined in <iomanip>
    cout<<setw(15)<<"Penguins "<<5<<3<<endl;
    cout<<setw(15)<<"Banana "<<2<<1<<endl;

    //left setw()
    cout<<left<<setw(12)<<"Anosh "<<7<<endl;
    cout<<setw(12)<<"Ingles "<<3<<endl;

    /*
    - most of manipulators change the state of stream
        - stream will remain in this state
        - to restore state we need to push manipulators which has opposite effect
        - These are called sticky
    - non sticky only affects next output operation on stream
    - only non sticky is setw()
    */

   //setfill(): 
   //- padding the argument
   //- sticky needs a reset: setfill('')
   cout<<setfill('#');
   cout<<left<<setw(12)<<"Ivan"<<3<<endl;
   cout<<setw(12)<<"Ingles"<<2<<endl;
   cout<<setfill(' ');
   cout<<left<<setw(12)<<"Ivan"<<3<<endl;
   cout<<setw(12)<<"Ingles"<<2<<endl;

    return 0;
}