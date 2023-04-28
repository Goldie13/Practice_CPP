#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

int main()
{
    auto printvec = [](auto v)
    {
        for_each(begin(v), end(v), [](auto i)
                 { cout << i << " "; });
    };

    vector<int> v1{3, 1, 4, 5, 9}, v2{1,2,5,6,3};
    random_device rd;
    static mt19937 mt(rd());
    shuffle(begin(v1), end(v1), mt);
    printvec(v1);
    cout << endl;

    /*
    - rearranges the elements in random fashion
    - calls Uniform distribution internally
    */

    /*
    bernoulli_distriution bd
    - rescales sequence of nos into boolean nos
    - useful for making on off decisions with random outcomes
    */
    static bernoulli_distribution bd;
    if(bd(mt)) {
        cout<<"yyy"<<endl;
    } else {
        cout<<"xxx"<<endl;
    }

    //  other option
    static uniform_int_distribution<int> uid(0, v2.size()-1);
    for(auto i=0; i<10; ++i)
    {
        swap(v2[i], v2[uid(mt)]);
    }
    for(auto i:v2)
    {
        cout<<i<<" ";
    }cout<<endl;
    return 0;
}