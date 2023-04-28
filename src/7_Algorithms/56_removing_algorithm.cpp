#include <bits/stdc++.h>
using namespace std;

class gen_n
{
    int n{0};
    public:
    int operator()(){++n; return n;}
};

int main()
{
    auto printvec = [](auto v){
        for_each(begin(v), end(v), [](auto i){ cout<<i<<" ";});
    };

    //  remove: given element is moved back of the container & size remains same
    vector<int> write_vec{1,2,3,1,4,1,5,6,7,1,1};
    cout<<"size: "<<write_vec.size()<<" & Vec before remove: "<<endl;printvec(write_vec);cout<<endl;
    auto first_removed_item_it = remove( begin(write_vec), end(write_vec), 1);
    cout<<"size: "<<write_vec.size()<<" & Vec after remove: "<<endl;printvec(write_vec);cout<<endl;
    cout<<" & index: "<<distance( begin(write_vec), first_removed_item_it );cout<<endl;

    //  erase: it will physically remove elements ; its a member function
    write_vec.erase( first_removed_item_it, end(write_vec) );
    cout<<"size: "<<write_vec.size()<<" & Vec after erase: "<<endl;printvec(write_vec);cout<<endl;

    //  remove_if
    //  _copy()
    //  remove_copy_if()

    //  unique():removes duplicate adjacent elements
    //  container must be sorted
    //  behaves same like remove() but in that elements are "logically" removed
    write_vec.clear();
    write_vec.assign({1,2,1,3,1,4,5,6});
    cout<<"size: "<<write_vec.size()<<" & Before unique: "<<endl;
    printvec(write_vec);cout<<endl;
    sort( begin(write_vec), end(write_vec) );;
    auto first_item_it = unique( begin(write_vec), end(write_vec) );
    cout<<"size: "<<write_vec.size()<<" & after unique: "<<endl;
    printvec( write_vec );cout<<endl;
    write_vec.erase( first_item_it, end(write_vec) );
    cout<<"size: "<<write_vec.size()<<" & after erase: "<<endl;
    printvec( write_vec );cout<<endl;

    //  unique_copy()

    //  transform()
    vector<int> backup;
    transform( begin(write_vec), end(write_vec), back_inserter(backup), [](int n){
        return 2 * n;
    } );
    printvec(backup);cout<<endl;

    //  transform() overloaded
    vector<int> result;
    transform( cbegin(write_vec), cend(write_vec), cbegin(backup), back_inserter(result), [=](int m, int n){
        return m * n;
    } );
    printvec(result);cout<<endl;

    //  transform to compare strings
    string s1{"Anosh"}, s2{"Ingles"}, s3{"Anosh"};
    auto equal_string = [=](const string s1, const string s2){
        if(s1.size() != s2.size())
            return false;

        string lhs{s1}, rhs{s2};
        transform( begin(s1), end(s1), begin(lhs), ::toupper );
        transform( begin(s2), end(s2), begin(rhs), ::toupper );

        return s1 == s2;
        
    };
    cout<<" s1 == s2: "<<boolalpha<<(equal_string(s1, s2))<<endl;
    cout<<" s1 == s3: "<<boolalpha<<(equal_string(s1, s3))<<endl;
    cout<<" s2 == s3: "<<boolalpha<<(equal_string(s2, s3))<<endl;
    return 0;
}