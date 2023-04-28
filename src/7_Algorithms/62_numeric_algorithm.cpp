#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    auto printvec = [](auto v)
    {
        for_each(begin(v), end(v), [](auto i)
                 { cout << i << " "; });
    };

    vector<int> v1{3, 5, 4, 6, 7, 9, 2, 8, 10}, v2, v3, v4, v5, v6;
    auto odd = [](int n)
    { return n % 2 != 0; };
    auto even = [](int n)
    { return n % 2 == 0; };

    //  partial_sum(): {a,a+b,a+b+c, a+b+c+d}
    v1.clear();
    v1.assign({1, 2, 3, 4, 5, 6});
    partial_sum(begin(v1), end(v1), back_inserter(v2));
    printvec(v2);
    cout << endl;

    //  adjacent_difference()
    /*
    - writes successive difference of one container to other container
    - inverse of partial sum
    - can be used for numerical differentiation
    - by default, - operator is used
    */
    adjacent_difference( begin(v2), end(v2), back_inserter(v3) );
    printvec(v3); cout<<endl;

    //  inner_product
    /*
    - multiplies the corresponding elements of two containers & calculat their sum
    - equal to scalar product
    - in accumulate we need to provide initial value of sum
    - equivalent to transform() followed by accumulate()
    */
    cout<<" v1: "<<endl;
    printvec(v1); cout<<endl;
    cout<<" v3: "<<endl;
    printvec(v3); cout<<endl;
    cout<<"after inner product result: "
    <<inner_product( cbegin(v1), cend(v1), cbegin(v3), 0 )<<endl;//91

    // with transform & accumulate
    copy( cbegin(v3), cend(v3), back_inserter(v5) );
    transform( begin(v1), end(v1), begin(v5), back_inserter(v6), [](const int& m, const int& n){
        return m * n;
    } );
    cout<<"transform & accumulate result: "
    <<accumulate( cbegin(v6), cend(v6), 0 ) <<endl;//91

    //  inner_product is not suitable parallel programming
    //  c++17 offers transform_reduce which uses reduce() instead of accumulate()
    return 0;
}