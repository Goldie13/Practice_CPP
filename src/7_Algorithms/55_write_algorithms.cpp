#include <bits/stdc++.h>
using namespace std;

class gen_n
{
    int n{0};
    public:
    int operator()(){++n; return n;}
};

int main()
{
    auto printvec = [](auto v){
        cout<<endl;
        for_each(begin(v), end(v), [](auto i){ cout<<i<<" ";});
    };

    //  replace
    vector<int> write_vec{1,2,3,1,4,1,5,6,7,1,1};
    replace( begin(write_vec), end(write_vec), 1, 3 );
    printvec(write_vec);cout<<endl;

    //  replace_n
    write_vec.clear(); cout<<write_vec.size()<<endl;
    generate_n( back_inserter(write_vec), 10 , gen_n() );//1 2 3 4 5
    printvec(write_vec);cout<<endl;
    auto geteven = [](int n){ return n-1;};
    replace_if( begin(write_vec), end(write_vec), [](int n){
        return n % 2 != 0;
    }, 2 );
    printvec(write_vec);cout<<endl;


    //  _copy()
    //  replace_copy()
    //  replace_if()    
    return 0;
}