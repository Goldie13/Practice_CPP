#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <random>
#include <list>

using namespace std;

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

    random_device rd;
    static mt19937 mt(rd());
    uniform_int_distribution<int> idist(1,20);
    array<list<int>,10> buckets;

    for(auto i=1; i<=150; ++i)
    {
        int num = idist(mt);
        /*
        - hash function generates the number based on the key
        - this is known as "hash" of the key
        - very fast operation
        - hash of the key is used as the index of the array 
        */
        int hash = (num-1)/10;
        buckets[hash].push_back(num);

        /* Hash collision
        - for max efficieny
            - each key produces different hash 
            - hash function to perform "perfect hashing"
            - if different key gives same hash then it hash collision
            - multimap & multiset cna have same key so it will long time & 
            more operation to perform search 
        */
    }
    //print out
    for(auto i=0; i<10; ++i)
    {
        auto bucket = buckets[i];
        cout<<"Bucket: "<< i <<endl;
        for(auto j:bucket)
        {
            cout<<j<<" , ";
        }cout<<endl;
    }cout<<endl;

    //find
    int target = 9;
    int idx_hash = (target-1)/10;
    auto it = find( cbegin(buckets[idx_hash]), cend(buckets[idx_hash]), target);
    if(it!=end(buckets[idx_hash])) {
        cout<<"found: "<<target<<" in bucket: "<<idx_hash<<endl;
    }
    return 0;
}