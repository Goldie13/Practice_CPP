/*
technique for sort or search
C++ STL defines number of function in <algorithm>
makes code shorter & simpler
highly flexible
code resue
more accurate & more efficient

Generic algorithm
- std::string() has find()
- perform searching only on string objects
- STL algorithm have global functions & can work on any types

Typical algorithm
- passed on iterator range
- which elements in container are to be proceesed
- algo will iterate on each element & will call function on each element
- eg find(): return iterator for first element
- eg sum(): return sum of all elements
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class descendingFunctor
{
public:
    //overloaded operator
    //take two integers
    //return if lhs > rhs
    bool operator()(const int &x, const int &y)
    {
        return x > y;
    }
    bool operator()(const string& s)
    {
        return s.size()<=4;
    }
};
bool descending(const int &x, const int& y)
{
    return x > y;
}

int main()
{
    string s{"Hello!"};
    auto it = find(cbegin(s), cend(s), 'l');
    if (it != cend(s))
    {
        cout << "Match found index: " << distance(cbegin(s), it) << endl;
    }

    it = find(cbegin(s), cend(s), 's');
    if (it != cend(s))
    {
        cout << "Match found index: " << distance(cbegin(s), it) << endl;
    }
    else
        cout << "Not found" << endl;

    /* Pseudocode for std::find()

    iter find(iter begin, iter end)
    {
        for(iter it = begin; it != end; ++it)
        {
            if(*it == target)
            {
                return it;
            }
        }
        return end;
    }
    */

    vector<int> vec{3, 4, 2, 1, 5, 9, 8};
    // sort(vec.begin(),vec.end(),descending);//function pointer as predicate
    sort(vec.begin(),vec.end(),descendingFunctor());//functor
    // sort(vec.begin(),vec.end());//ascending
    for (auto i : vec)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}