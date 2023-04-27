#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//without state
class le_4
{
    public:
    bool operator()(const string& s)
    {
        return s.size()<=4;
    }
};

//state
class le
{
    const int m_i;
    public:
    le(const int i) : m_i{i}{}
    bool operator()(const string& s)
    {
        return s.size()<=m_i;
    }
};

int main()
{
    //option 1:
    vector<string> vecStr{"Anosh","Shejal","Ivan","Ajji"};
    le_4 obj;
    for(auto name: vecStr)
    {
        cout << boolalpha;
        cout << name << " has size less than 4: " << obj(name) << endl;
    }

    //option 2: using find_if
    auto it = find_if(vecStr.begin(),vecStr.end(),le_4());
    if(it != vecStr.cend())
        cout<<"first element Less than size 4: "<<*it<<endl;
    else cout<<"Not found"<<endl;

    it = find_if_not(vecStr.begin(),vecStr.end(),le_4());
    if(it != vecStr.cend())
        cout<<"first element greater than size 4: "<<*it<<endl;
    else cout<<"Not found"<<endl;

    it = find_if(vecStr.begin(),vecStr.end(),le(4));
    if(it != vecStr.cend())
        cout<<"first element occurrence less than size 4 using state: "<<*it<<endl;
    else cout<<"Not found"<<endl;

    /* Pseudo implementation
    iter find_if(iter begin, iter end)
    {
        for(iter begin; iter != end; ++iter)
        {
            if(func(*it)) {
                return it;
            }
        }
        return end;
    }
    */
    return 0;
}