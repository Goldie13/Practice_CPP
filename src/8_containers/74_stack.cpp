#include <iostream>
#include <stack>
using namespace std;

int main()
{
    /*
    problem statement is
    string of characters like [{("''")}] - true
    string of characters like [{("<''")}] - false
    */
    auto printStack = [](const auto &st) {
        auto printSt{st};
        auto size = printSt.size();
        cout << " no of elements in stack: " <<size << endl;
        cout << " top: " << printSt.top() << endl;
        cout << " elements in stack are: " << endl;

        for(auto i=0; i<size; ++i)
        {
            cout<<printSt.top()<<" ";
            printSt.pop();
        }cout<<endl;
    };

    stack<int> st;
    st.push(5);
    st.push(3);
    st.push(2);
    st.push(4);
    st.push(1);
    printStack(st);
    return 0;
}