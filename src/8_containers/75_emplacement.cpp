/*
another way to add elements
push_back() / insert() require existing object
    it copies existing object into the new element
    if there is no object we need to form temporary object
with emplacement, container creates the object in the new element instead of copying it
    this avoid copy constructor call
*/

#include <iostream>
#include <vector>
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
    vector<refrigerator> vec;
    
    //creates a obj
    refrigerator ref(3);

    //add existing obj in insert
    vec.insert(begin(vec), ref);//1 copy ctors

    //temporary obj creation in insert
    vec.insert(end(vec), refrigerator(6));// 2 copy ctors

    //both have copy ctor calls
    //solved by emplacement
    vec.clear();
    vec.emplace(begin(vec),3);//no copy ctor

    //emplace_back()
    vec.clear();
    vec.emplace_back(3);//no copy ctor

    //emplace_front() can be used for different containers
    //std::set & std::map, emplace() creates a temporary object
    //it then check whether there is an item with the same key

    // this is solved in map with:
    /*
    try_emplace() which first check for existing item with same key
    before creating temporary object
    if item exists, no temporary oject
    */
    //goto 69_map for eg

    return 0;
}