#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    // luxsoft question
    auto printLst = [](const auto& lst){
        for_each( begin(lst), end(lst), [](const auto i){
            cout<<i<<" ";
        } );
    };

    string str{"abcbabccccddd"};
    set<char> seteg;
    for (char i : str)
    {
        cout << i << " ";
        seteg.insert(i);
    }
    cout << endl;
    printLst(seteg);cout<<endl;

    // multiset
    multiset<int> multiset;
    multiset.insert(5);
    multiset.insert(3);
    multiset.insert(1);
    multiset.insert(1);
    multiset.insert(4);
    multiset.insert(4);
    multiset.insert(2);
    cout<<"Multiset: "<<endl;
    printLst(multiset);cout<<endl;
    return 0;
}