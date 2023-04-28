#include <bits/stdc++.h>
using namespace std;

int main()
{
    //  Find_first_of
    string findFirstOfStr{"Hello I am Anosh"};
    string vowels{"aeiou"};
    auto it = find_first_of(cbegin(findFirstOfStr),cend(findFirstOfStr),cbegin(vowels),cend(vowels));
    cout<<"Find first of vowel is : "<<*it
    <<" & index: "
    <<( (it != cend(findFirstOfStr)) ? distance(cbegin(findFirstOfStr),it) : -1)<<endl;

    auto it2 = (find_first_of(next(it),cend(findFirstOfStr),cbegin(vowels),cend(vowels)));
    cout<<"Find second of vowel is : "<<*it2
    <<" & index: "
    <<( (it2 != cend(findFirstOfStr)) ? distance(cbegin(findFirstOfStr),it2) : -1)<<endl;

    //  adjacent_find
    string adjacentFindStr{"Hello"};
    it = adjacent_find(cbegin(adjacentFindStr),cend(adjacentFindStr));
    cout<<"adjacent charcater: "<<*it<<" & index: "<<distance(cbegin(adjacentFindStr),it)<<endl;
    
    //  search_n
    vector<int> vec{1,2,3,4,4,5,6,7,7};
    auto it3 = search_n(cbegin(vec), cend(vec), 2, 4);
    cout<<"repeatitive value by 2 is : "<<*it3
    <<" & index is : "<<(distance(cbegin(vec), it3))<<endl;

    //  search: similar to find sub string in string
    string searchStr{"Hello World"}, subStr{"Wo"};
    it = search(cbegin(searchStr), cend(searchStr), cbegin(subStr), cend(subStr));
    cout<<"sub str exist: "<<( (it != cend(searchStr) ) ? (*it) : ' ' )
    <<" & Index: "<<( (it != cend(searchStr) ) ? (distance( cbegin(searchStr), it )) : (-1) )<<endl;

    //  mismatch: return pair of iterator of mistmatched elements of containers
    vector<int> v1{1,2,3,4,5,6,7,8};
    vector<int> v2{1,2,3,4,5,66,7,8,9};
    auto it_mismatch = mismatch( cbegin(v1), cend(v2), cbegin(v2), cend(v2) );
    cout<<"Mismatch 1st no: "<<*it_mismatch.first<<" & 2nd no is: "<<*it_mismatch.second<<endl;

    return 0;
}