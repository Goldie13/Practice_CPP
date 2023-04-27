/*
Write a function that takes a vector of int as argument and uses a range-for loop to print out the elements of the vector.

Write a program that calls this function. Check that your program compiles and runs correctly.

Modify your program so that it sorts the elements in descending order, with the largest element first. For example, if the vector elements are 1, 2, 3, 4, 5, the output will be

5, 4, 3, 2, 1

Use a suitable standard algorithm with a lambda expression as predicate.

Display the elements of the vector after sorting them. Check that your program still compiles and runs correctly.

Questions for this assignment
Implement the program as described. If you need help, click on "Instructor Example" for some hints.

*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void printVec(vector<int>& vectorOfInt)
{
    for(auto i:vectorOfInt)
    {
        cout<<i<<" ";
    }cout<<endl;
}
int main()
{
    vector<int> vectorOfInt {1,2,3,4,5};
    //Lambda with predicate
    sort(vectorOfInt.begin(), vectorOfInt.end(), [](const int& lhs, const int& rhs){ return lhs > rhs;});
    printVec(vectorOfInt);
    return 0;
}