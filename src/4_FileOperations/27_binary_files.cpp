#include <iostream>
#include <fstream>
using namespace std;

//it removes the padding bytes; 9 bytes final
//without this 12 bytes final
#pragma pack(push, 1)
struct point
{
    char c;
    int32_t x;
    int32_t y;
};
#pragma pack(pop)
//it removes the padding bytes; 9 bytes final
//without this 12 bytes final

int main()
{
    string path_out{"/root/Anosh/Practice_CPP/sample.bin"};
    point p{'a', 1, 2};
    ofstream ofile(path_out, fstream::binary);
    if(true == ofile.is_open()){
        ofile.write(reinterpret_cast<char *>(&p), sizeof(point));
        ofile.close();
    } else return 0;
    
    ifstream ifile{"/root/Anosh/Practice_CPP/sample.bin"};
    point p2;
    if(true == ifile.is_open()){
        ifile.read(reinterpret_cast<char*>(&p2),sizeof(point));
        ifile.close();
        cout<<"read "<<ifile.gcount()<<" bytes of data"<<endl;
        cout<<"read x: "<<p2.x<<" y: "<<p2.y<<endl;
    } else return 0;
    return 0;
}