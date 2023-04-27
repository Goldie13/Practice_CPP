/* equal() algorithm
- to compare elements in two containers
- bool cmp(cbegin(ct1), cend(ct2), cbegin(ct2), cend(ct2))
- iterates through each elements in two containers
- as soon as it finds mismtaches return false
- extra elements are ignore in one of the container
- std == operator is used by default
- if its std::string, comparison will be case senstive
- There is a overload of equal() algorithm which takes predicate
- this predicate will be called instead of == operator
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool equalStrings(const string &s1, const string &s2)
{
    if (s1.size() != s2.size())
        return false;

    auto lhs_it = s1.begin();
    auto rhs_it = s2.begin();

    while (lhs_it != s1.end() && rhs_it != s2.end())
    {
        if (*lhs_it != *rhs_it)
            return false;
        lhs_it++;
        rhs_it++;
    }
    return true;
}

bool equalStringswithAlgo(const string &s1, const string &s2)
{
    return equal(s1.begin(), s1.end(), s2.begin(), s2.end(),[](const char& c1, const char& c2){
        return toupper(c1) == toupper(c2);
    });
}

void test(const string& s1, const string& s2)
{
    cout<<s1<<" and "<<s2<<" are "<<((equalStrings(s1, s2))?"":"Not ")<<"equal"<<endl;
}

void testWithAlgo(const string& s1, const string& s2)
{
    cout<<s1<<" and "<<s2<<" are "<<((equalStringswithAlgo(s1, s2))?"":"Not ")<<"equal"<<endl;
}

int main()
{
    string s1{"Anosh"};
    string s2{"Ingles"};
    string s3{"Anosh"};
    test(s1, s2);
    test(s1, s3);
    test(s1, s2);
    cout<<endl;
    testWithAlgo(s1, s2);
    testWithAlgo(s1, s3);
    testWithAlgo(s1, s2);
    return 0;
}