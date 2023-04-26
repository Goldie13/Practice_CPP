
/* 
c++ streams use "buffering" to minimize call to OS
during write operations, data is temporarily held in memory buffer
size of buffer = OS accepting the data
if buffer is full, stream remove the data & send it to OS
This is known as flushing of output buffer
*/

/* when are stream flushed
- for ostream, it depends on terminal configuration
    - usually EOL
    - cout is always flushed before program reads from cin
- ofstream is always flushed when buffer is full
- no direct way to flush cin
*/

/* std::flush 
- allows more control when stream buffer is flushed
- all data is immediately sent to destination
- it should when we data up-to-date
- e.g log file to find out why program crashed
*/

#include <iostream>
#include <fstream>
using namespace std::literals;
using namespace std;

int main()
{
    string path_out{"/root/Anosh/Practice_CPP/log_out.txt"};
    ofstream ofile(path_out.c_str());

    for(auto i=0; i<1'000'000; ++i)
    {
        // cout<<i<<"\n";
        // cout<<i<<"\n"<<flush;
        cout<<i<<"\n"<<endl;//same result flush
        // ofile<<i<<"\n";
        // ofile<<i<<"\n"<<flush;
        ofile<<i<<"\n"<<endl;//same result like flush

        if(i==66666){
            std::terminate();
        }
    }
    ofile.close();
    return 0;
}