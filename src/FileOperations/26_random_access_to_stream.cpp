/*Resources
we often use resources:
- heap memory
- files
- database connections
- GUI windows

These resources has to be managed
- we have to allocate, open & acquire resource before use
- we have to release or close resource after use
- we may need to give special thought to copying resource
- we may need to think on error handling 
*/

/* 
c++ stream position marker (stores when last operation was stopped)
this keeps tracks when next read or write will be performed
programmer can alter its position 
    - fstream not open in app mode
    - stringstream
this allows us to read or write data anywhere

seek member is used to change the marker position
seekg: set the current position in an input stream
    - 
seekp: set the current position in an output stream
    - seekp(pos): pos_object can be used as argument for seekp
    - this will set the current position as per pos_object in the stream
    - std::ios_base provides three base positions
        - beg: beginning of stream
        - end: end of stream
        - cur: current marker position
    - e.g seekp(-10, std::ios_base::end);move position marker 10 characters before the end 

tellg: returns the current position in an input stream
    - return pos_type object & can be converted to int
    - return -1 for invalid state
tellp: return the current position in an output stream
    - return pos_type object & can be converted to int
    - return -1 for invalid state
*/

#include <iostream>
#include <sstream>
#include <iterator> // for istream / ostream ierator
#include <vector>
using namespace std;

int main()
{
    string data{"its time to say "};
    ostringstream ss;
    ss<<data;
    auto marker = ss.tellp();
    cout<<"No of characters in data: "<<data.size()<<endl;
    cout<<"marker now: "<<marker<<" in ss stream"<<endl;
    ss<<"its Anosh";
    cout<<"ss stream now: "<<ss.str()<<" :: marker now: "<<ss.tellp()<<endl;
    if(marker != -1){
        ss.seekp(marker);
        cout<<"ss stream now: "<<ss.str()<<" :: marker now: "<<ss.tellp()<<endl;
    }
    ss<<" Helloooooo";
    cout<<"ss stream now: "<<ss.str()<<" :: marker now: "<<ss.tellp()<<endl;

    /* stream ierators
    defined in <iterator>
    istream_iterator reads input stream
    ostream_ierator write outout stream
    */

    ostream_iterator<int> oi(cout, "\n");
    for(auto i=0;i<10;++i)
    {
        *oi = i;
        ++oi;//next marker position
    }

    cout<<"Enter the no: "<<endl;
    istream_iterator<int>ii(cin);
    int x = *ii;
    cout<<"No entered is: "<<x<<endl;

    //comparison
    cout<<"enter the name: "<<endl;
    istream_iterator<string> eof;//empty iterator
    istream_iterator<string> iis(cin);
    vector<string> names;
    while(iis != eof) {
        names.push_back(*iis);
        ++iis;
    }
    for(auto o:names)
    {
        cout<<o<<endl;
    }

    return 0;
}