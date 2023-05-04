#include <iostream>
#include <memory>
using namespace std;

struct Point
{
    int x;
    int y;
};

//unique_ptr as a return
unique_ptr<Point> ret_func()
{
    auto temp_point{make_unique<Point>(Point{3,2})};
    cout<<"address of temp obj: "<<&temp_point<<endl;
    return temp_point;
}

//unique_ptr as a arg
void add_func(unique_ptr<Point> pointPtr)
{
    cout<<"address of pointPtr obj: "<<&pointPtr<<endl;
    cout<<pointPtr->x+pointPtr->y<<endl;
}

int main()
{
    // c++11 we need to provide ptr by calling new() explicitly

    // c++11 initialisation
    std::unique_ptr<Point> struct_up_ptr{new Point{4,2}};//points to int on heap
    //or
    auto struct_up_ptr2{make_unique<Point>(Point{4,2})};
    
    cout<<struct_up_ptr->x<<" "<<struct_up_ptr2->x<<endl;
    cout<<struct_up_ptr->y<<" "<<struct_up_ptr2->y<<endl;

    // std::move has to be used
    // add_func(std::move(struct_up_ptr));// pass it as arg
    // add_func(std::move(struct_up_ptr2));// pass it as arg
    add_func(ret_func());// return
    return 0;
}