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

    //  reverse(): doesnt change the elements only order is changed
    string str{"Hello"};
    reverse( begin(str), end(str) );
    cout<<"reverse: "<<str<<endl;

    //  reverse_copy
    string str_copy;
    reverse_copy( begin(str), end(str), back_inserter(str_copy) );
    cout<<"reverse copy: "<<str_copy<<endl;

    //rotate()
    vector<int> roatate_vec{1,2,3,4,5};
    auto pivot = begin(roatate_vec);
    // advance(pivot, 1);//2 3 4 5 1
    // advance(pivot, 2);//3 4 5 1 2
    // advance(pivot, 3);//4 5 1 2 3
    advance(pivot, 4);//5 1 2 3 4
    rotate( begin(roatate_vec), pivot, end(roatate_vec) );
    printvec(roatate_vec); cout<< endl;

    //rotate_copy()
    return 0;
}