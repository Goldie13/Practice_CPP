#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

/*
- queue is DS in which elements are stored in order
in which they are stored
*/

int main()
{
    auto printQ = [=](const auto& q){
        cout<<" the queue is "<<(q.empty()?"":"not")<<" empty";
        auto size = q.size();
        cout<<" the queue contains "<<q.size()<<" elements\n";
        cout<<" the front element is "<<q.front()<<endl;
        cout<<" the back element is "<<q.back()<<endl;
        cout<<" the elements are: "<<endl;
        auto printq{q};
        for(auto i=0; i<size; i++)
        {
            cout<<printq.front()<<" ";
            printq.pop();
        }cout<<endl;
    };

    auto printPQ = [=](const auto& q){
        cout<<" the queue is "<<(q.empty()?"":"not")<<" empty";
        auto size = q.size();
        cout<<" the queue contains "<<q.size()<<" elements\n";
        cout<<" the front element is "<<q.top()<<endl;
        cout<<" the elements are: "<<endl;
        auto printq{q};
        for(auto i=0; i<size; i++)
        {
            cout<<printq.top()<<" ";
            printq.pop();
        }cout<<endl;
    };

    queue<int> q;
    q.push(1);
    q.push(3);
    q.push(2);
    q.push(4);
    printQ(q);
    q.push(6);
    printQ(q);

    priority_queue<int> pq;
    pq.push(4);
    pq.push(3);
    pq.push(5);
    pq.push(5);
    pq.push(1);
    printPQ(pq);
    return 0;
}