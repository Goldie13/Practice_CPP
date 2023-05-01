/* 
Write an inheritance hierarchy with three classes: Base, Child and Grandchild. Do not define any constructors or data members for these classes.

Child inherits from Base and Grandchild inherits from Child.

Give each class a print() member function which prints out the name of the class

Write a print_class() function which takes a Base argument by value

Create an object of each class and pass it to a call to print_class()

Questions for this assignment
Implement the program as described. Explain your results.

Change the print() member function to be virtual.

Run the program again and explain your results.

Change print_function() so that its argument is passed by reference.

Run the program again and explain your results.

Add an integer member to the Base class. Provide a constructor which initializes this member from its argument.

Why does the program not compile?

What is the best way to solve this problem?
*/

#include <iostream>
using namespace std;

class BaseClass
{
    int i{0};
    public:
        // BaseClass() = default;
        // BaseClass(const int x):i(x){} 
        // void virtual print(){ cout<<" Base "<<endl; }
        void print(){ cout<<" Base "<<endl; }
};

class ChildClass : public BaseClass
{
    public:
        void print(){ cout<<" Child "<<endl; }
};

class GrandChildClass : public ChildClass
{
    public:
        void print(){ cout<<" GrandChild "<<endl; }
};

void print_class(::BaseClass& base_class)
{
    base_class.print();
}

int main()
{
    BaseClass b; print_class(b);
    ChildClass c; print_class(c);
    GrandChildClass g; print_class(g);
    return 0;
}

/* 1. Implement the program as described. Explain your results.
- even though we passed objects of base; child & grandchild to print_class function, 
compiler will consider base class object only & will execute base class member function print.
this is the problem with OOPs and member functions of base class is not marked virtual nor 
we marked members functions in derived classes as override.
result will name of base class will be printed 3 times
*/

/* 2. Change the print() member function to be virtual.
- even though we marked base class member function as "virtual", 
due to static binding compiler still consider only base class member function & 
as it is static binding its decided during compile time
- same result: name of base class will be printed 3 times
*/

/* 3. Change print_function() so that its argument is passed by reference.
- as argument is changed to reference compiler cannot decide anything during compile time which 
object it is referenced to
- it will be decided during compile time which is dynamic binding
- result: names of base, child & grandchild class will be printed
*/

/* 4. Add an integer member to the Base class. Provide a constructor which initializes this member from its argument.
Why does the program not compile?
- default constructor will be implcitly deleted by compiler and therefore 
when child & grandchild objects wont be created & it will throw an error as compiler
will nto default constructor
*/

/* 5. What is the best way to solve this problem?
- define the empty constructor with no arguements
*/