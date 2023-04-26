#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

/* functors
allows to make callable objects
    - object of class is a variable
    - object can be called like a function
c++ which implements function call operator is called functors
functors are classes with member or non member functions
to keep it simple they used only be used to "wrap" function
they can have data members to store values used between function calls known as "state"
*/
class evenp
{
    int m_i;
    public:
    evenp(int x):m_i(x){}
    bool operator()(int n)
    {
        return (n%2 == 0);
    }
    friend ostream& operator<<(ostream& os, const int& i);
    void print(ostream& os) const
    {
        os<<"i: "<<this->m_i<<" ";
    }
};

ostream &operator<<(ostream &os, const evenp& ev)
{
    ev.print(os);
    return os;
}

int main()
{
    evenp even_obj{5};
    vector<int> vec{1,2,4,5,8,10,12,15,16};
    for(auto i:vec)
    {
        cout<<boolalpha;
        cout<<setw(10)<<i<<" is even: "<<even_obj(i)<<endl;
    }
    even_obj.print(cout);
    cout<<endl;
    return 0;
}