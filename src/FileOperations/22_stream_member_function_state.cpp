#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int x{0};
    cout<<"Enter the no: "<<endl;
    cin>>x;

    if(true == cin.good())//stream member functions
        cout<<"you enetered no: "<<x<<endl;
    if(true == cin.bad())//stream member functions
        cout<<"pls try again, enter no again"<<endl;
    if(true == cin.fail())//stream member functions
        cout<<"failed pls try again"<<endl;

    //clear(): restores the streams state to valid

    //eof: end of file
    string path{"/root/Anosh/Practice_CPP/sample_in.txt"};
    ifstream ifile(path);
    int y{0};

    // while(false == ifile.eof()) {

    //     ifile>>y;
    //     cout<<y<<",";
    // }

    while(ifile>>y) {
        cout<<y<<",";
    }
    
    /*
    No flush for cin
    but we can use cin.ignore() member function to ignore the uncleared characters
    e.g: cin.ignore(20, '\n');//ignore characters till new line 
    */
    cout<<endl;
    return 0;

}