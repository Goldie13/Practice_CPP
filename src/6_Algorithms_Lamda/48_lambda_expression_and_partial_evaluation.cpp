#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
storing lambads:
used for implementing temporary functions
lambdas are also called as "first class objects"
we can store them in variables & pass them to a function
    auto longer_than = [max](const string& str){ return str.size()>max;}
    find_if(cbegin(words), cend(words), longer_than);
*/

/* Partial evaluation
eg: formatting pages of the document viewer
reduces computation
can make processing simple
we can use lamda expressions with capture for partial evaluation for processing simple
*/
int main()
{
    int max{4};
    auto is_longer_than = [=](const string& names){
        return names.size() > max;
    };

    vector<string> names{"Ivan","Ingles","I","ajji"};

    cout<<"names greater than "<<max<<" characters is: "
    <<*(find_if_not(cbegin(names), cend(names),is_longer_than))<<endl;

    return 0;
}