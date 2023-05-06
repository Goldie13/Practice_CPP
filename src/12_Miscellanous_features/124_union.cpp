#include <iostream>
#include <string>
#include <variant>
using namespace std;

enum TokenType { Char, Int, Double };

// only member in use other if used will be undefined
union token
{
    // memebers are public by default
    /* data */
    char c;
    int i;
    double d;
    TokenType type;
};


int main()
{
    token t;
    t.type = TokenType::Double;
    t.d = 8.9;
    try {
        cout<<" try to member which is not use: "
        << ((TokenType::Double == t.type)?t.d:0.0)<<endl;
    } catch(std::exception& ex)
    {
        cout<<ex.what()<<endl;
    }

    // above is the eg of tagged union 
    /* c++17 comes with inbuilt std::variant similar to tagged union
    - type safe
    - can have diff alternatives with same type
    - automatically calls ctor & dtors when required
    - simpler to use
    - used for parsing (ini) configuration files
    */

    /* uncomment to use in c++17
    variant<char, int, double> v;
    // v = 'Z'; //char is in use
    v = 4.5;
    
    if(holds_alternative<double>(v))
        cout<<get<double>(v)<<endl;
    else
        cout<<"Double member not in use"<<endl;
    */
    return 0;
}