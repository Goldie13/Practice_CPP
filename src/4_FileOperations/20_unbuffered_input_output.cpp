/*
some applications where stream buffering is not suitable
e.g network application
    - Data must be transmitted in "packets" of a specifed size 
    - Data may need to be transmitted at specific times

c++ supports low level operations
- these bypass stream buffers
- no formatting of data

These are mainly used when programmers need to know how data is transmitted
- network applications
- communicating directly with the hardware
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // cout<<"enter some text: "<<endl;
    // char c;
    //for this we need to terminate the program
    // while(cin.get(c)) //Read char untill end-of-line
    //     cout.put(c);//display the character
    
    //For this we need to have our own buffers for reading & writing
    string path{"/root/Anosh/Practice_CPP/sample_in.txt"};
    ifstream ifile(path);

    const int size{50};//buffer size
    char fileBuf[size];//memory buffer

    if(false == ifile.is_open()) {
        cout<<"Not opened"<<endl;
        return 0;
    }

    //read member function with custom created buffer
    ifile.read(fileBuf, size);//fetch data from file into buffer we created
    auto nread = ifile.gcount();//gives count of bytes read from file
    ifile.close();

    cout<<"read "<<nread<<" bytes of data received from file"<<endl;
    cout<<"Write data: ";
    cout.write(fileBuf,size);//writing from buffer to destination or console
    cout<<flush;

    return 0;
}