#include <iostream>
#include <memory>
#include <array>
#include <vector>
using namespace std;

/*
- best replacement for traditional pointers or auto_ptr (c++98)
- manages heap memory
    - allocated heap memory in ctor & release in dtor
    - follows RAII
    - allows heap memory to be used like stack obj
- adv:
    - programmers doesnt need to manage memory
    - pointer to memory cannot be overwritten or invalidated
    - no issues in "shallow copying"
- unique_ptr is very lighweight
    - unique_ptr object has no more overhead than traditional pointer

- defined in <memory>
- it is template class with a tradiitonal pointer as a member
- public member functions of the class implement some of the operations on traditional ptrs
- its template parameter is type of the pointed data
    - unique_ptr<int> p;
- unique_ptr is a move only class
    - moving unique_ptr transfers allocated memory from one unique_ptr obj to another unique_ptr obj

*/


int main()
{
    // c++11 we need to provide ptr by calling new() explicitly

    // allocate single int with value 42
    std::unique_ptr<int> int_up_ptr{new int{42}};//points to int on heap

    //allocate array of 6 ints
    unique_ptr<int[]> int_arr_up_ptr{ new int[6]};//points to 1st element of array on heap

    // better to use std::array or std::vector
    std::unique_ptr<std::array<int, 6>> int_array_up_ptr{new array<int, 6>()};
    std::unique_ptr<std::vector<int>> int_vec_up_ptr{new vector<int>(6)};

    //c++14 use make_unique
    auto int_up_ptr2{ make_unique<int>(42) };
    auto int_arr_up_ptr2{ make_unique<int[]>(6) };
    auto int_array_up_ptr2{ make_unique<std::array<int,6>>() };
    auto int_vec_up_ptr2{ make_unique<std::vector<int>>(6) };

    cout<<*int_up_ptr<<endl;//single ptr dereferenced
    // cout<<int_up_ptr[0]<<endl;//error! single obj can not be indexed
    // above: type 'std::unique_ptr<int>' does not provide a subscript operator
    cout<<int_arr_up_ptr[2]<<endl;//array can be indexed
    // cout<<*int_arr_up_ptr<<endl;//cannot be dereferenced
    // ++int_arr_up_ptr;//ptr arithmetic not allowed
    // int_arr_up_ptr++;//ptr arithmetic not allowed
    // unique_ptr<int[]> p(int_arr_up_ptr);// unique_ptr can only be moved
    unique_ptr<int[]> int_arr_up_ptr_moved(std::move(int_arr_up_ptr)); //allowed only for unique ptr obj
    // unique_ptr<int> int_up_ptr_moved(int_vec_up_ptr);// Error! incompatible types
    int_arr_up_ptr = nullptr;// calls delete on the pointer member

    return 0;
}