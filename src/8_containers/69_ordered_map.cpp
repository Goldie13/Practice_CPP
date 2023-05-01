#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class refrigerator
{
    int i;
    public:
    refrigerator(int x):i(x){}
    refrigerator(const refrigerator& ref_copy)
    {
        cout<<"copy ctor"<<endl;
    }
};

int main()
{
    // luxsoft question
    auto printLst = [](const auto& lst){
        for_each( begin(lst), end(lst), [](const auto i){
            cout<<i<<" ";
        } );
    };

    auto printMaps = [](const auto& lst){
        for(auto i:lst)
        {
            cout<<i.first<<" "<<i.second<<" ";
        }cout<<endl;
    };

    string str{"abcbabccccddd"};
    sort ( begin(str), end(str) );
    printLst(str);cout<<endl;

    //output should be:
    // a 2
    // b 3
    // c 5
    // d 3

    map<char, int> map, map1;
    for(auto i=0; i<str.size(); ++i)
    {
        map[str[i]]++;
    }

    for(auto i:map)
    {
        if(i.second>0)
            cout<<i.first<<" "<<i.second<<endl;
    }
    
    //  insert
    cout << "Inserted: "<<map.insert({'e', 1}).second<<endl;
    auto refVar = map['f']=4;//doesnt exit but it will create it
    //  refVar will reference to the value which is 4 added // refVar=>'f' 4
    cout<<"refVar: "<<refVar<<endl;
    
    auto search = map.find('f');
    // search->first = 'g';// not possible need to comment
    search->second = 6;// value can be changed but not key
    for(auto i:map)
    {
        if(i.second>0)
            cout<<i.first<<" "<<i.second<<endl;
    }

    // maps in c++17
    pair<int, double> p(1,3.14);

    //  multimap
    multimap<string, int> multimap;
    multimap.insert({"Anosh", 1001});
    multimap.insert({"shejal", 1002});
    multimap.insert({"Ivan", 1003});
    multimap.insert({"Ajji", 1004});
    printMaps(multimap);cout<<endl;

    // find()  count()
    // to get duplicate items
    multimap.clear();cout<<"size after clearing: "<<multimap.size()<<endl;
    multimap.emplace("Anosh", 2);
    multimap.emplace("Anosh", 3);
    multimap.emplace("Ingles", 4);
    multimap.emplace("Anosh", 2);
    multimap.emplace("Ingles", 2);
    multimap.emplace("Anosh", 5);
    auto it = multimap.find("Anosh");
    auto count  = multimap.count("Anosh");
    auto last = begin(multimap);
    advance( last, count );
    cout<<"count of duplicate items: "<<count<<endl;
    cout<<"Items: "<<endl;
    for(auto i = it; i!=last; ++i)
    {
        cout<<i->first<<" : "<<i->second
        <<" index: "<<distance( begin(multimap), i ) <<endl;
    }cout<<endl;

    //  lower & upper bound
    ::multimap<int, int> m_map;
    m_map.emplace(3, 1001);
    m_map.emplace(4, 1002);
    m_map.emplace(5, 1003);
    m_map.emplace(1, 1004);
    auto lower = m_map.lower_bound(1);
    auto upper = m_map.upper_bound(1);
    cout<<" lower bound: key: "<<lower->first<<" second: "<<lower->second<<endl;
    cout<<" upper bound: "<<upper->first<<" second: "<<upper->second<<endl;
    auto equal_range = m_map.equal_range(1);
    for (auto i = equal_range.first; i != equal_range.second; ++i)
    {
        cout << "first: " << i->first<<" second: "<<i->second<<endl;
    }cout<<endl;

    ::map<int, refrigerator> ref_map;
    ref_map.insert(begin(ref_map),{3, refrigerator(3)}); //2 copy ctor

    //solved this by emplace with 1 copy ctor
    ref_map.emplace(3, refrigerator(3));// 1 copy ctor

    //solve this by try_emplace()
    ref_map.clear();
    // ref_map.try_emplace(2, refrigerator(2));
    return 0;
}