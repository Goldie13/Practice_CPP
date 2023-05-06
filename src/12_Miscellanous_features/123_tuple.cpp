#include <iostream>
#include <tuple>
#include <string>
using namespace std;

// auto function(double x, int y, string z) -> tuple<double,int,string>
auto function(double x, int y, string z)
{
    auto p{make_tuple(x,y,z)};
    return p;
}

// uncomment to run only for c++17
// struct Point
// {
//     double m_x;
//     int m_y;
//     string m_z;
    
//     Point(double x, int y, string z):m_x(x),m_y(y),m_z(z){}
//     void print()
//     {
//         cout<<" x: double: "<<m_x
//         <<" y: int: "<<m_y
//         <<" z: string: "<<m_z
//         <<endl;
//     }
// };

int main()
{
    tuple<double, int, string> t1{3.33, 45, "anosh"};
    auto t2{make_tuple<double, int, string>(3.33, 45, "anosh")};

    // access using get()
    cout<<"t1: double: "<<std::get<0>(t1)
    <<" & int: "<<get<1>(t1)
    <<" & string: "<<get<2>(t1)
    <<endl;

    //c++14
    auto i = get<int>(t1);
    cout<<"c++14 t1: int: "<<i<<endl;

    // unpacking tuple
    double x; int y; string z;
    tie(x,y,z) = t1;
    cout<<"tie: double: "<<x
    <<" & int: "<<y
    <<" & string: "<<z
    <<endl;

    cout<<"return from function: double: "<< 
    get<double>(function(3.456, 78, "Ingles"))<<endl;

    /* only in c++17
    tuple t2{3.56, 67, "aaa"};// 
    // only in c++17
    tuple t2{4.56, 67, "aaa"};
    cout<<"t2: int: "<<get<int>(t2)<<endl;
    auto[a,b,c] = func(5.65, 34, "xxx");
    cout<<"return func: double: "<<a<<endl;

    // unpacking tuple as func arg only in c++17
    tuple as func arg
    auto[d,e,f] = std::apply(funcTupleAsArg,tuple{12.3, 90, "funcTupleAsArg"});
    cout<<"return funcTupleAsArg: double: "<<e<<endl;

    //make_from_tuple
    auto p = make_from_tuple<Point>(tuple{8.88, 54, "make_from_tuple"});
    p.print();
    */
    return 0;
}