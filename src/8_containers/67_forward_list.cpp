#include <iostream>
#include <forward_list>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    //  Singly Linked lists
    forward_list<int> fw_list{4,3,1,2};
    cout<<"Initial elements are: "<<endl;
    auto printLst = [](const auto& lst){
        for_each( begin(lst), end(lst), [](const int i){
            cout<<i<<" ";
        } );
    };
    printLst(fw_list); cout<<endl;

    //insert at 2 index
    auto second = begin(fw_list);
    advance( second, 1);
    cout<<"before insert at 1: "<<*second<<endl;
    fw_list.insert_after( second, 4 );
    cout<<"after insert: "<<endl;
    printLst(fw_list);cout<<endl;

    //erase 
    auto it = find( begin(fw_list), end(fw_list), 1 );
    fw_list.erase_after(it);
    cout<<"after erase: "<<endl;
    printLst(fw_list);cout<<endl;

    //  splice_after almost same like splice

    //  doubly Linked lists
    list<int> lst{4,2,1,5};
    cout<<"DLL initialise elements: "<<endl;
    printLst(lst);cout<<endl;

    auto insertItem = begin(lst);
    advance( insertItem, 1 );
    lst.insert( insertItem, 3);
    cout<<"DLL after insert: "<<endl;
    printLst(lst);cout<<endl;

    // sort( begin(lst), end(lst) );//as random access is not possible sort cant be used
    lst.sort();
    printLst(lst);cout<<endl;

    //  generic remove will remove elements from list
    //  no need to call erase like other containers
    lst.remove(4);
    printLst(lst);cout<<endl;

    //  merge
    list<int> lst1{1,2,3},lst2{4,5};
    lst1.merge(lst2);
    printLst(lst1);cout<<endl;
    cout<<"size of list2: "<<lst2.size()<<endl;

    //  splice
    lst1.assign({1,4,5}),lst2.assign({2,3});
    auto spliceIt = begin(lst1);advance( spliceIt, 1 );
    lst1.splice( spliceIt, lst2 );
    printLst( lst1 ); cout<<endl;
    return 0;
}