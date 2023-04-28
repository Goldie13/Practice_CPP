#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    auto printvec = [](auto v)
    {
        for_each(begin(v), end(v), [](auto i)
                 { cout << i << " "; });
    };

    vector<int> v1{3, 5, 4, 6, 7, 9, 2, 8, 10};
    auto odd = [](int n)
    { return n % 2 != 0; };
    auto even = [](int n)
    { return n % 2 == 0; };

    /*next_permutation()
    - if elements are in ascending order calling next permutation
    in a loop gives all permutations
    */
    vector<int> s{4, 2, 1}, s2;
    copy(begin(s), end(s), back_inserter(s2));
    sort(begin(s), end(s)); // sort in ascending order
    cout << "Permutation with sort: " << endl;
    do
    {
        for_each(begin(s), end(s), [](const int n)
                 { cout << n << " "; });
        // as its sorted it will give all permutations
    } while (true == next_permutation(begin(s), end(s)));
    cout << endl;

    cout << "Permutation without sort: " << endl;
    do
    {
        for_each(begin(s2), end(s2), [](const int n)
                 { cout << n << " "; }); // 421 as its not sorted
    } while (true == next_permutation(begin(s2), end(s2)));
    cout << endl;

    /*previous_permutation()
    - sort container in descending order
    - then same like next_permutation
    */
    s.clear();
    s.assign({4, 2, 1});
    sort(begin(s), end(s), greater<int>()); // sort in descending order
    cout << "Permutation with sort in reverse: " << endl;
    do
    {
        for_each(begin(s), end(s), [](const int n)
                 { cout << n << " "; });
        // as its sorted it will give all permutations in reverse
    } while (true == prev_permutation(begin(s), end(s)));
    cout << endl;

    //  is_permutation()
    s.clear();
    s.assign({4,2,1,5,6,7});
    s2.clear();
    s2.assign({1,5,6,4,2,7});
    cout<<"s is a permutation of s2: "
    <<boolalpha<<( is_permutation( begin(s), end(s), begin(s2), end(s2) ) ) <<endl;

    //  min & max
    s.clear();
    s.assign({4,5,6,7,3,2,8,1});
    printvec(s); cout<<endl;
    sort( begin(s), end(s) );
    s2.clear();
    s2.assign({10,100,1});
    printvec(s2); cout<<endl;
    sort( begin(s2), end(s2) );
    // cout<<"min element in s: "<<*min( begin(s), end(s) )<<endl;
    cout<<"max element in s2: "<<*max( cbegin(s2), cend(s2) )<<endl;
    // auto min_max = minmax( begin(s), end(s) );
    // cout<<"minmax element in s: min: "<<*min_max.first
    // <<" & max: "<<*min_max.second<<endl;
    return 0;
}