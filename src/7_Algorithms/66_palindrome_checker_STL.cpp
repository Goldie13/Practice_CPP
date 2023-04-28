#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string str{"Anosh I hsonA!"}, copy_str{""};
    copy_if( cbegin(str), cend(str), back_inserter(copy_str), [](const char c){
        return isalpha(c);
    });
    transform( begin(copy_str), end(copy_str), begin(copy_str), [](const char n){
        return tolower(n);
    });
    auto p = mismatch( cbegin(copy_str), cend(copy_str), crbegin(copy_str));
    if(p.first == cend(copy_str))
        cout << "Palindrome"<<endl;
    else 
        cout << "Not Palindrome"<<endl;
    return 0;
}