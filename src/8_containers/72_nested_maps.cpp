#include <map>
#include <iostream>
using namespace std;

//typedef level_map = map<int, map<int, string>>
using level_map = map<int, map<int, string>>;

int main()
{
    //print
    auto printNestedMaps = [](const auto mp) {
        for (auto i : mp)
        {
            cout << "level: " << i.first << " map: " << endl;
            for (auto j : i.second)
            {
                cout << " ( " << j.first << " " << j.second << " ) ";
            }
            cout << endl;
        }
        cout << endl;
    };
    // map<int, map<int, string>> nestedMaps
    level_map nestedMaps
    {
        {1,{{1, "player"},{10, "door"}}},
        {2, {{5, "player"},{10, "monster"}}}
    };

    cout<<"Game Map: "<<endl;
    printNestedMaps(nestedMaps);cout<<endl;

    //insert map
    auto insertMap = nestedMaps.find(2);
    auto inserted = insertMap->second.insert({11,"Gamer"});

    //insert level
    nestedMaps.insert({3,{{6, "player"},{10, "Acts"}}});
    printNestedMaps(nestedMaps);cout<<endl;
    return 0;
}