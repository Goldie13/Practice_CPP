#include <iostream>
using namespace std::literals;
using namespace std;
/*
c++14 always deduce the return type of lamda expression
return type is simply auto
we can also use auto in the arguments of lamda expression
these are known as "generic lambdas" or "polymorphic lambdas"
most requested feature in c++14
*/

int main()
{
    auto func = [=](const auto &x, const auto &y)
    {
        return x + y;
    };

    /* compiler generates the functor
    class lamda_func_unique_name
    {
        public:
        template<typename T>
        T operator()(T x, T y)
        {
            return x+y;//lambda expression body
        }
    }
    create functor object, instantiate its function call operator and call it
    lambda_func_unique_name()(2,5);
    */

    cout << func(3, 2) << endl;
    cout << func(3.4, 2.7) << endl;
    cout << func("Anosh "s, "Ingles"s) << endl;

    // local variables only for lambda expression
    [y = 2]()
    {
        cout << "Local variable scope for lambda c++14: " << y * y << endl;
    }();

    int z = 1;
    auto func_cpp14 = [y = z + 1](int x)
    {
        return y * x;
    };
    cout << "Local variables scope with capture variable c++14: " << func_cpp14(4) << endl;

    /*
    compiler will generate following code:
    class functorclass
    {
        T y;
        public:
        functorclass(T z): y(z+1){}
        T operator()(int x){
            return y*x;
        }
    }

    Instantiate: functorclass<int> func_cpp14(z);
    call: func_cpp14(x);
    */

   /* capture by move: 2nd most requested feature of c++14

   Generalized lambda capture allows capture by move 
   
   */
    return 0;
}