

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> strings(5);

    cout<<"capture by ref: "<<endl;
    [&strings](){ cout << " Size in lamda: "<<strings.size()<<endl; }();
    cout<<"After calling lamda, size in main: "<<strings.size()<<endl;

    cout<<endl<<"Capture by move: "<<endl;
    [vs = std::move(strings)](){
        cout<<"Size in lamda: "<<vs.size()<<endl;
    }();
    cout<<"After calling lamda, size in main: "<<strings.size()<<endl<<endl;
    return 0;
} 

/* lambda & move only objects
- c++11 lamda expressions are not good at capturing 
move only objects
- fstream fs("output.txt")
- [fs] //capture by value does not compile
- [&fs] //capture by ref does not compile
- [???]

- Can be solved by catpure by move
- c++14 capture by move
- using "generalise lamda"
- [ lfs = std::move(fs)](){}
- this is allowed cpature by move
    - lfs is deduced as fstream
    - move ctor is called to initalize lfs
    - lfs will take ownership of the file handle
*/