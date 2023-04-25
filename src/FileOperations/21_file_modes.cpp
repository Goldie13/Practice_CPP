/*
c++ gives lot of options for opening the file
- we can pass the file mode as optional in second argument
- by default files are opened in text mode
- by default output files are opened in truncated mode
    - all old data will be overritten
    - new data will be written from start of file
*/

/* Appending the files
- to open ofstream in append mode, we pass fstream::app as 
  second arg to open
- once we do this, current data will be preserved
- new data will added after the data that was already there
*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Text Mode
    string path_out{"/root/Anosh/Practice_CPP/sample_out.txt"};
    ofstream ofile(path_out, fstream::app);

    if(false == ofile.is_open()) {
        cout<<"not opened"<<endl;
        return 0;
    }

    ofile << "I am okay";
    ofile.close();

    //end

    //Binary Mode
    /*
    - in binary mode, data is stored like in memory
    - e.g 42 is stored like ascii characters binary equivalent (4: 110100 2: 110010)
    - this mode is complex, error prone and should be avoided
    - it is needed when working on media files 
    */
    /*
    other modes:
    - trunc mode
    - in mode: open file for input
    - out mode: 
        - open file on output mode
        - also in truncate mode even if truncate is not specified
    - ate: similar to append but output can be written anywhere in the file
    */

    //end
    return 0;
}