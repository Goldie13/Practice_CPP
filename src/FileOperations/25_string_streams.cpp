#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>
using namespace std;

template<class T>
string to_string(const T& s)
{
    ostringstream ss;
    ss<<s;
    return ss.str();
}

int main()
{
    /* c++ stream types
    iostream: ostream (cout) istream(cin)
    fstream: 
        ofstream (file stream for writing)
        ifstream (file stream for reading)
    stringstream:
        ostringstream (string stream for writing)
        istringstream (string stream for reading)
    */
    /* stringstream
    - defined in <sstream>
    - has std::string as a data member
    - has same member functions like other stream types
    - its actually wrapper around std::string class making it like a stream object
    - similar adapter design pattern over std::string
    */
    
    //ostringstream used as to_string function for any type
    cout<<"int: "<<to_string(3)<<" float: "<<to_string(3.145f)
    <<" double: "<<to_string(456.34567)<<endl;

    string name;
    ostringstream os;
    cout<<"enter the 1st name: "<<endl;
    cin>>name;
    os<<setw(8)<<name;
    cout<<"Enter the 2nd name: "<<endl;
    cin>>name;
    os<<setw(8)<<name;
    cout<<"final string: "<<os.str()<<endl;

    /*istringstream
    - istringstream uses copy of an existing string
        - this string is passed to the istringstream constructor
    - we can read data from the string using same operations like other input streams
    - this is USEFUL FOR PROCESSING INPUTS
        - e.g BREAKING UP LINE OF TEXT INTO WORDS OR NUMBERS
    */

    string path{"/root/Anosh/Practice_CPP/sample_in.txt"};
    ifstream ifile(path);
    string input;
    vector<int> numbers;
    if(false == ifile.is_open()) {
        cout<<"Not opened"<<endl;
        return 0;
    }
    while(getline(ifile,input)){
        istringstream is(input);
        int num;
        while(is >> num) {
            numbers.push_back(num);
        }
    }

    double sum{0};
    for(auto i:numbers)
    {
        sum += i;
    }
    cout<<"average: "<<sum/numbers.size()<<endl;

    /* Application stringstreams
    - ostringstream are useful when interfacing to systems that expect string in particular format
        - GUI; OS; third party library
    - istringstream can be used with getline() to process input more easily than with the >> operator
    */
    return 0;
}