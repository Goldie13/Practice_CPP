#include <iostream>
using namespace std;

// non variadic template
template<typename T>
void func(T t)
{
    cout<<"non variadic template"<<endl;
    cout<<"Processing arg: "<<t<<endl;
}

// variadic template
template<typename T, typename... Args>//Args is a list of types  
void func(T t, Args... args)
{
    size_t n_args = sizeof...(args)+1;
    cout<<"Variadic template : compiler has deduced variadic call with "
    << n_args<<" argument(s)"<<endl;
    cout<<"Processing argument: "<<endl;

    // to avoid overhead of template specialization
    // c++17 has constexpr
    if( n_args > 0 )
        func(args...);
}

int main()
{
    int i{42}; double d{4.5}; string s{"abc"};
    func(i, d, s);

    return 0;
}