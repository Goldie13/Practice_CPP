#include <iostream>
#include <vector>
using namespace std;

// generic template
template<typename T>
class Vector
{
    public:
    void identify()
    {
        cout<<"Vector<T>"<<endl;
    }
};

// specialised template
template<>
class Vector<bool>
{
    public:
    void identify()
    {
        cout<<"Vector<bool>"<<endl;
    }
};

//partial specialization
template<typename T>
class Vector<T*>
{
    public:
    void identify()
    {
        cout<<"Vector<T*>"<<endl;
    }
};

int main()
{
    Vector<int> ivec;
    Vector<bool> bvec;
    Vector<int*> iptrvec;
    cout<<"Vector<int> identify: "<<endl;
    ivec.identify();
    cout<<"Vector<bool> identify: "<<endl;
    bvec.identify();
    cout<<"Vector<int*> identify: "<<endl;
    iptrvec.identify();
    return 0;
}