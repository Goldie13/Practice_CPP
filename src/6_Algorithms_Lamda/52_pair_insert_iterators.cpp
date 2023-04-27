#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

template<typename T>
void printVec(vector<T>& vec)
{
    for(auto i:vec)
    {
        cout<<i<<" ";
    }cout<<endl;
}

int main()
{
    vector<int> vec;

    cout<<" vec: ";printVec<int>(vec);cout<<endl;cout<<" vec size: "<<vec.size()<<endl;

    auto it = back_inserter(vec);//assign to back inserter
    *it = 88;//call to push_back
    *it = 99;//call to push_back

    cout<<" vec: "<<endl;printVec<int>(vec);cout<<" vec size: "<<vec.size()<<endl;

    //front_insert_iterator is similar 
    //except it calls push_front()
    //does not work on vector or string
    vector<int> vec2{1,2,3};
    auto nxt = next(begin(vec2));//iterator to next position after begin
    auto it2 = inserter(vec2,nxt);
    *it2 = 99;//it will call vec.insert(99)
    cout<<" vec: "<<endl;printVec<int>(vec2);cout<<" vec size: "<<vec2.size()<<endl;

    //application of insert iterator work with conjunction of stream iterators
    cout<<"enter the word: "<<endl;
    istream_iterator<string> iis(cin);
    istream_iterator<string> eof;//empty iterator


    vector<string> vec3;
    auto it3 = back_inserter(vec3);

    while(iis != eof){
        it3 = *iis;
        ++iis;
    }

    cout<<" vec: "<<endl;printVec<string>(vec3);cout<<" vec size: "<<vec3.size()<<endl;
    return 0;
}