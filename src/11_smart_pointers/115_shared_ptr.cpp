#include <iostream>
#include <memory>
using namespace std;

int main()
{
    shared_ptr<int> p1{ new int{42}};
    unique_ptr<int> p5{ new int{52}};

    cout<<*p1<<endl;// Single obj dereferenced
    //++p1; //not allowed
    //p1++; //not allowed
    shared_ptr<int> p2(p1); cout<<*p2<<endl; // copy shared
    cout<<"ref of count p1: "<<p1.use_count()
    <<" & p2: "<<p2.use_count()<<endl;
    shared_ptr<int> p3 = p1;
    cout<<"ref of count p1: "<<p1.use_count()
    <<" & p2: "<<p2.use_count()<<" & p3: "<<p3.use_count()<<endl;
    shared_ptr<int> p4 { std::move(p2) };
    cout<<"ref of count p1: "<<p1.use_count()
    <<" & p2: "<<p2.use_count()<<" & p3: "<<p3.use_count()
    << " & p4: "<<p4.use_count() <<endl;
    p1 = nullptr;
    cout<<"ref of count p1: "<<p1.use_count()
    <<" & p2: "<<p2.use_count()<<" & p3: "<<p3.use_count()
    << " & p4: "<<p4.use_count() <<endl;
    std::shared_ptr<int> p6 = std::move(p5);
    cout<<"ref of count p1: "<<p1.use_count()
    <<" & p2: "<<p2.use_count()<<" & p3: "<<p3.use_count()
    << " & p4: "<<p4.use_count() <<" & p6: " << p6.use_count()
    <<" & is_unique:  "<<p6.unique()<<endl;
    return 0;
}