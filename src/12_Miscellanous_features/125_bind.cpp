

/*** only in c++17*/
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std::placeholders;

bool match(const string& animal, const string& species)
{
    cout<<R"(1st arg is")"<<animal<<R"(", 2nd arg is ")"<<species<<"\""<<endl;
    return (animal == species);
}

int main()
{
    
    auto match_cat = std::bind(match, _1, "cat");
    // above will bind match function with 2nd arg as "cat" & return the obj in match_cat
    
    vector<string> animals{
        "dog","cat","horse","lion","tiger","rat"
    };
    cout<<"vector contains: ";
    cout<<count_if( begin(animals), end(animals), match_cat );
    //above will use obj passed by match_cat & pass animal as 1st arg to match
    cout<<" occurrence of word \"cat\""<<endl;
    
    
    return 0;
}
*/