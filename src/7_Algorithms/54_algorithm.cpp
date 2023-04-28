#include <bits/stdc++.h>
using namespace std;

class gen_n
{
    int n{0};
    public:
    int operator()(){++n; return n*n;}
};

int main()
{
    //INTRODUCED in C++11
    //  for_each: same like for
    vector<int> foreachVec(10,2);
    for_each( begin(foreachVec), end(foreachVec), [](int n) { cout<<n<<" "; } );cout<<endl;
    for_each( begin(foreachVec), end(foreachVec), [](int n) { cout<<n+1<<" "; } );cout<<endl;

    auto printvec = [](auto v){
        cout<<endl;
        for_each(begin(v), end(v), [](auto i){ cout<<i<<" ";});
    };
    
    //  copying algorithms
    //  - copy one iterator rangeof container to other iterator range of container
    vector<int> copy_vec_1{1,2,3,4,5};
    vector<int> copy_vec_2(copy_vec_1.size());
    copy( cbegin(copy_vec_1), cend(copy_vec_1), begin(copy_vec_2) );
    printvec(copy_vec_2);
    copy_vec_2.clear();
    copy( cbegin(copy_vec_1), cend(copy_vec_2), back_inserter(copy_vec_2) );
    printvec( copy_vec_2 );

    //  copy_n: 

    //  copy_if
    copy_vec_2.clear();
    copy_if( cbegin(copy_vec_1), cend(copy_vec_1), back_inserter(copy_vec_2), [](const int& n){ return ((n%2) == 0); } );
    printvec( copy_vec_2 );


    return 0;
}