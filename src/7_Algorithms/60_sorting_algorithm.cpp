#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    auto printvec = [](auto v)
    {
        for_each(begin(v), end(v), [](auto i)
                 { cout << i << " "; });
    };

    vector<int> v1{3,5,4,6,7,9,2,8,10};
    auto odd = [](int n){ return n % 2 != 0;};
    auto even = [](int n){ return n % 2 == 0;};

    /* sort()
    - usually implemented in ascending order
    - elements which have the same key may have their order change
    - use stable_sort to maintain order
    */

    //  is_sorted_untill: returns iterator to element which is not sorted
    cout<<"element which unsorted: "
    <<*(is_sorted_until( begin(v1), end(v1) ))<<endl;

    // sort( begin(v1), end(v1), greater<int>() ); //change order
    stable_sort( begin(v1), end(v1), greater<int>() );//does not change order of duplicate items
    printvec(v1); cout<<endl;

    //  is_sorted()
    cout<<"is sorted: "<<boolalpha
    <<( is_sorted( begin(v1), end(v1), greater<int>() ))<<endl;

    //  partial_sort()
    partial_sort( begin(v1), begin(v1)+3, end(v1) );
    printvec(v1);cout<<endl;

    //  partial_sort_copy()

    // nth element
    v1.clear();
    v1.assign({3,5,4,6,7,9,2,8,10});
    cout<<"nth element before sort: "<<endl;printvec(v1); cout<<endl;
    sort( begin(v1), end(v1) );
    cout<<"nth element after sort: "<<endl;printvec(v1); cout<<endl;
    
    auto mid = begin(v1) + 4;
    nth_element( begin(v1), mid, end(v1) );
    cout<<"mid element: "<<*mid<<endl;
    printvec(v1);cout<<endl;
    return 0;
}