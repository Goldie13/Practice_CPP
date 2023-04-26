/*
You are given the attached languages.txt file and the following type definition:

struct language {
    string lang;
    string designer;
    int date;
};
The format of the languages.txt file is:

C++ Stroustrup 1979
Java Gosling 1991
Write a program which will:

Read in the data from the attached languages.txt file

Use each line of input to populate a language object

Add this object to a vector

Print out all the data in the vector, separated by commas

Your output should look like this:

C++, Stroustrup, 1979
Java, Gosling, 1991


Questions for this assignment
Implement the program as described. If you need help, click on the Instructor Example to get some hints.
*/

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    string path{"/root/Anosh/Practice_CPP/languages2.txt"};
    ifstream ifile(path, fstream::in);//in mode

    if(false == ifile.is_open()) {
        cout<<"File not opened"<<endl;
        return 0;
    }

    vector<string> output;
    string input;
    while(getline(ifile, input)){
        istringstream is(input);
        string tempStr;
        while(is >> tempStr) {
            output.push_back(tempStr);
        }
        for (auto i = output.begin(); i != output.end(); ++i)
        {
            cout << *i <<" ";
        } cout<<endl;
        output.clear();
    }
    return 0;
}