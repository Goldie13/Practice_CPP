/*
Consider the following code (do not compile it yet!)

int y = 1;
[y = y+1](int x) { return x + y; };
cout << y << endl;
Questions for this assignment

Explain what the code does.
:
1. Variable y is declared & defined with value 1 in the scope of main
2. [y = y+1](int x) { return x + y; }; Lambda expression is unsued & compiler will give warning as 
this lambda expression is not invoked
3. Variable y will remain unchanged & 1 will be printed

What will be the result of calling the lambda expression with argument 5?:
if argument 5 lambda expression, then compiler will execute the lambda expression or generate
the functor class local capture variable y = 2, lamda expression will return x+y:2+5: 7


What will be displayed as the final value of y?:
1

Write a program to check your answers.
*/
#include <iostream>
using namespace std;

int main()
{
    int y = 1;
    cout<<"Lamda return: "<<[y = y + 1](int x)
    { return x + y; }(5)<<endl;
    cout << y << endl;
    /*
    class unique_name
    {
        T y;
        public:
        unique_name(y):y(y+1){}
        T operator()(int x)
        {
            return x+y;
        }
    };
    */
    return 0;
}