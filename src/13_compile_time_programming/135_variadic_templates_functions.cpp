#include <iostream>
#include <tuple>
using namespace std;

// template<typename... Args>
// void func( Args... args )
// {
//     cout<<"compiler has deduced call with: "<<
//     sizeof...(args)<<" argument(s)"<<endl;
// }

//using tuple
template<typename... Args>
void func( Args... args )
{
    auto arg_tuple = make_tuple(args...);
    auto first = get<0>(arg_tuple);
    cout<<"first arg: "<<first<<endl;
}

int main()
{
    int i{42}; double d{4.5}; string s{"abc"};

    func(s);
    func(i,d,s);

    return 0;
}