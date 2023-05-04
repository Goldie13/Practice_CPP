#include <iostream>
#include <memory>
using namespace std;

class Body
{
    public:
        void print(){ cout<<"Body print"<<endl; }
};

class Handle
{
    private:
        unique_ptr<Body> pBody;
    public:
        Handle(): pBody(make_unique<Body>(Body{})){}
        void print(){ pBody->print(); }
        ~Handle() noexcept = default;// if dtor then we need to declare move operators
        Handle(Handle&& obj) noexcept = default;
        Handle& operator=(Handle&& obj) noexcept = default;        
};

int main()
{
    unique_ptr<Handle> phandle { make_unique<Handle>(Handle{}) };
    phandle->print();
    return 0;
}

/* Applications of pImpl
- often used for large objects
- heavily used in QT library
- used in container classes like std::string 
*/