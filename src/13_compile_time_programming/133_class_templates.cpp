#include <iostream>
#include <string>

using namespace std;

template<typename T>
class comparer{
    T t1, t2;
    public:
        comparer(const T& t1, const T& t2):t1(t1), t2(t2){}

        // member template with parameter func
        template<typename Func>
        bool compare(Func f){ return f(t1,t2) ;}

};
 
int main()
{
    int x{1}, y{2};comparer<int> comp(x,y);
    cout<<"greater: "<<
    comp.compare([](int i, int j){ return (i>j);  } )
    <<endl;

    return 0;
}