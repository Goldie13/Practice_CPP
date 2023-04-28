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

    vector<int> v1{3,1,4,1,5,9,2,8,6};
    auto odd = [](int n){ return n % 2 != 0;};
    auto even = [](int n){ return n % 2 == 0;};

    //  partition: order is not maintained
    //  partition( begin(v1), end(v1), odd );
    //  printvec(v1); cout<<endl;

    //  stable partition: order is maintained
    stable_partition( begin(v1), end(v1), odd );
    printvec(v1); cout<<endl;

    //  is_partitioned(): 
    cout<<"Is paritioned: "<<boolalpha
    // <<( is_partitioned( begin(v1), end(v1), even ) )<<endl; //FALSE
    <<( is_partitioned( begin(v1), end(v1), odd ) )<<endl; //TRUE

    //  partition_point(): return iterator to the element which was false
    cout<<"partition point: "
    <<*( partition_point( begin(v1), end(v1), odd ) )<<endl; 
    return 0;
}