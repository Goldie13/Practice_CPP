#include <iostream>
#include <algorithm>
using namespace std;

class String {
private:
    int size;
    char* data;
public:
    //  ctor
    String(int size):size(size),data(new char[size]){}

    //  copy ctor
    String(const String& arg) = delete;

    // assignment operator
    String& operator=(const String& arg) = delete;

    // move ctor
    String(String&& arg) noexcept : size(arg.size)
    {
        data = arg.data;
        //Error! why???
        // because when arg is moved to this
        // arg becomes invalid and dtor tries to delete it
        // thats pointer is invalid & programs termainates
        // add below 
        arg.size = 0;
        arg.data = nullptr;
    }

    // move assignment operator
    String& operator=(String&& arg)
    {
        // if(this != &arg) {
        //     delete[] data;
        //     data = new char[arg.size];
        //     auto size = arg.size;
        //     for(auto i=0; i<size; ++i)
        //     {
        //         this->data[i] = arg.data[i];
        //     }
        // }
        // arg.data = nullptr;
        // arg.size = 0;

        //or
        //no exception guarantee
        //copy-and-swap
        String temp{std::move(arg)};
        ::swap(*this, temp);
        return *this;
    }

    //dtor
    ~String()
    {
        cout<<"dtor"<<endl;
        delete[] data;
    }

    //using inline function will deduce copy ctor call 
    //so use std::swap in this function
    friend void swap( String& l, String& r );

    void print()
    {
        cout << "String with size:  "<<size;
        cout<<" , data address "<<static_cast<void*>(data)<<endl;
    }
};

inline void swap( String& l, String& r )
{
    using std::swap;
    swap(l.size, r.size);
    swap(l.data, r.data);
}

int main()
{
    String a{5};
    cout<<"a: "; a.print();
    {
        String b{6}; cout<<"b: "; b.print();
        cout<<"move construction of d from b: "<<endl;
        String d{std::move(b)};
        cout<<"b: "; b.print();
        cout<<"d: "; d.print();
        cout<<"copy move assignment of f from a: "<<endl;
        String f = std::move(a);
        cout<<"a: "; a.print();
        cout<<"f: "; f.print();
    }
    return 0;
}

/* move only types:
- has some types which cannot be copied but can be moved
- fstream, iostream
- (classes used in multithreading)
- ("Smart pointer" class)
- these types follow RAII
    - only one obj can own given resource instance at a time
    - obj acquire ownership of the resource in the ctor
    - obj releases ownership of the resource in the dtor
- ownership of resource can be transferred from one obj to another
using move semantics
*/

/* Output: 

a: String with size:  5 , data address 0x55b7d6f70eb0
b: String with size:  6 , data address 0x55b7d6f712e0
move construction of d from b: 
b: String with size:  0 , data address 0
d: String with size:  6 , data address 0x55b7d6f712e0
copy move assignment of f from a: 
a: String with size:  0 , data address 0
f: String with size:  5 , data address 0x55b7d6f70eb0
dtor
dtor
dtor
dtor

*/