#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    /* Merge()
    - combines two sorted integers ranges into destination
    - it will contain all the elements from both ranges in order
    - in theory, it is sum of ranges
    - by default, < operator is used in merge
    */

    auto printvec = [](auto v)
    {
        for_each(begin(v), end(v), [](auto i)
                 { cout << i << " "; });
    };
    vector<int> v1{5, 3, 1, 2, 4, 9, 7, 6, 8};
    vector<int> v2{15, 13, 1, 10, 14, 12};
    vector<int> v3;

    sort( begin(v1), end(v1) );
    sort( begin(v2), end(v2) );

    merge(begin(v1), end(v1), begin(v2), end(v2), back_inserter(v3));
    printvec(v3);cout<<endl;

    /* set_intersection()
    - combines two sorted integers ranges into a destination
    - destination will contain only elements which are present in both ranges
    - by default, < operator are used
    */
    v3.clear();
    set_intersection( begin(v1), end(v1), begin(v2), end(v2), back_inserter(v3) );
    printvec(v3);cout<<endl;

    /* set_union()
    - combines two sorted integers ranges into a destination
    - destination will contain elements which are present in either range
    - by default, < operator is used
    */
    v3.clear();
    set_union( begin(v1), end(v1), begin(v2), end(v2), back_inserter(v3) );
    printvec(v3);cout<<endl;
    return 0;
}