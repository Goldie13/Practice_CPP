
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

/* std::pair
defined in <utility>
two public members : first & second
can be used to return two related data items from a function
is used by some of the containers in STL
std::pair: templated type
    when we call pair we need specify types of both members
    pair<string, string>wordpair{"hello","there"}
    wordpair.first  //hello
    wordpair.second //there
we can call make_pair to create pair variable
    auto wordpair{make_pair{"hello","there"}
c++17 compiler can deduce types
    pair wordpair{"hello"s,"there"s} //c++17 CTAD
*/

//functor class
class ge_than
{
    int m_max;
    public:
    ge_than(int max):m_max(max){}
    bool operator()(const string& name)
    {
        return name.size() > m_max;
    }
};

// pair<string, int> printVecIndex(vector<string>& names, int max)
auto printVecIndex(vector<string>& names, int max)
{
    int idx{-1};

    //lamda function
    auto res = find_if(cbegin(names), cend(names),[max, &idx](const string& s){
        ++idx;
        return s.size() > max;
        }
    );

    //functor class with predicate
    res = find_if(cbegin(names),cend(names),ge_than(max));

    if(cend(names) != res) {
        return pair<string,int>{*res, idx};
    } else {
        return pair<string,int>{""s, idx};
    }
}

int main()
{
    //c++17
    // pair wordpair{"hello"s,"there"s};

    pair<string,string> wordpair{"hello","there"};
    auto wordpair2{ make_pair("hello"s,"there"s) };
    cout<<wordpair.first<<" "<<wordpair.second<<endl;

    vector<string> names {"Ivan", "Ajji","Anosh","Ingles"};
    int max = 4;
    auto res = printVecIndex(names, max);
    cout<<"name with more than "<<max<<" characters is: "
    <<res.first<<" & index: "<<res.second<<endl;
    return 0;
}