#include <iostream>
#include <memory>
using namespace std;

int main()
{
    //create shared_ptr<int> obj
    auto ptr{make_shared<int>(36)};
    cout<<"shared_ptr data: "<<*ptr<<endl;

    // create weak_ptr alias to ptr
    weak_ptr<int> wptr = ptr;// weak ptr bound to shared_ptr

    //release ptr shared memory
    ptr = nullptr;

    // wptr is alias to ptr -> still valid?
    shared_ptr<int> sp1 = wptr.lock();

    if(sp1){
        cout<<"shared ptr data: "<<*sp1<<endl;
    } else {
        cout<<"Not valid"<<endl;
    }
    return 0;
}

/* Applications
- cache implementation
    - data stored in shared_ptr objs
    - cache holds weak_ptr to data
    - use lock() to retrieve data
    - original data returned if not expired
    - otherwise need to fetch again
*/