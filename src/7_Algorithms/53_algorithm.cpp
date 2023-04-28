#include <bits/stdc++.h>
using namespace std;

class gen_n
{
    int n{0};
    public:
    int operator()(){++n; return n*n;}
};

int main()
{
    //  Find_first_of
    string findFirstOfStr{"Hello I am Anosh"};
    string vowels{"aeiou"};
    auto it = find_first_of(cbegin(findFirstOfStr),cend(findFirstOfStr),cbegin(vowels),cend(vowels));
    cout<<"Find first of vowel is : "<<*it
    <<" & index: "
    <<( (it != cend(findFirstOfStr)) ? distance(cbegin(findFirstOfStr),it) : -1)<<endl;

    auto it2 = (find_first_of(next(it),cend(findFirstOfStr),cbegin(vowels),cend(vowels)));
    cout<<"Find second of vowel is : "<<*it2
    <<" & index: "
    <<( (it2 != cend(findFirstOfStr)) ? distance(cbegin(findFirstOfStr),it2) : -1)<<endl;

    //  adjacent_find
    string adjacentFindStr{"Hello"};
    it = adjacent_find(cbegin(adjacentFindStr),cend(adjacentFindStr));
    cout<<"adjacent charcater: "<<*it<<" & index: "<<distance(cbegin(adjacentFindStr),it)<<endl;
    
    //  search_n
    vector<int> vec{1,2,3,4,4,5,6,7,7};
    auto it3 = search_n(cbegin(vec), cend(vec), 2, 4);
    cout<<"repeatitive value by 2 is : "<<*it3
    <<" & index is : "<<(distance(cbegin(vec), it3))<<endl;

    //  search: similar to find sub string in string
    string searchStr{"Hello World"}, subStr{"Wo"};
    it = search(cbegin(searchStr), cend(searchStr), cbegin(subStr), cend(subStr));
    cout<<"sub str exist: "<<( (it != cend(searchStr) ) ? (*it) : ' ' )
    <<" & Index: "<<( (it != cend(searchStr) ) ? (distance( cbegin(searchStr), it )) : (-1) )<<endl;

    //  mismatch: return pair of iterator of mistmatched elements of containers
    vector<int> v1{1,2,3,4,5,6,7,8};
    vector<int> v2{1,2,3,4,5,66,7,8,9};
    auto it_mismatch = mismatch( cbegin(v1), cend(v2), cbegin(v2), cend(v2) );
    cout<<"Mismatch 1st no: "<<*it_mismatch.first<<" & 2nd no is: "<<*it_mismatch.second<<endl;

    //  all_of; any_of; none_of: returns true/false
    auto even = [](int n) { return ( n % 2 ) == 0; };
    auto odd = [](int n) { return (n % 2 ) != 0; };
    vector<int> allOfVecIntEven{2,4,6,3,10};
    vector<int> allOfVecIntOdd{1,3,5,7,9};
    bool all_of_res = all_of( cbegin(allOfVecIntEven), cend(allOfVecIntEven), even );
    cout<<boolalpha<<"all of even: "<<all_of_res<<endl;
    cout<<"all of odd: "<<all_of( cbegin(allOfVecIntOdd), cend(allOfVecIntOdd), odd )<<endl;
    cout<<"any of even: "<<any_of( cbegin(allOfVecIntEven), cend(allOfVecIntEven), odd )<<endl;
    cout<<"none of even: "<<none_of( cbegin(allOfVecIntEven), cend(allOfVecIntEven), odd )<<noboolalpha<< endl;

    //  binarysearch: similar to find()
    vector<int> binarySearchVecOfInt{1,2,3,4,5,77,8,99};
    cout<<"to find no in unsorted vector: "<<boolalpha<<binary_search( cbegin(binarySearchVecOfInt), cend(binarySearchVecOfInt), 77 )<<endl;
    sort( begin(binarySearchVecOfInt), end(binarySearchVecOfInt) );
    cout<<"to find no in sorted vector: "<<boolalpha<<binary_search( cbegin(binarySearchVecOfInt), cend(binarySearchVecOfInt), 77 )<<endl;

    //  includes(): search whether all characters are present in the container
    string includeStr{"Hello includes all"};
    sort( begin(includeStr), end(includeStr) );
    sort( begin(vowels), end(vowels) );
    bool result = includes( cbegin(includeStr), cend(includeStr), cbegin(vowels), cend(vowels) );
    cout<<"String contains all vowels: "<<boolalpha<<result<<endl;

    //  iota: takes iterator range & increases value by 1
    vector<int> iota_vec(10);
    auto printVec = [&](){ for(auto i:iota_vec){cout<<i<<" ";}cout<<endl; };
    printVec();
    iota( begin(iota_vec), end(iota_vec), 0 );
    printVec();

    //  accumulate: linear / sequential addition of each element
    cout<<"sum of iota_vec: "<<accumulate( begin(iota_vec), end(iota_vec), 0 )<<endl;
    auto square = [](int sum, int n) { return (sum + (n*n));};
    cout<<"sum of squares of iota_vec: "
    <<accumulate( begin(iota_vec), end(iota_vec), 0 , square)<<endl;

    //  c++17: reduce() similar like accumulate but with parallel processing
    // cout<<"sum of iota_vec with reduce: "<<std::reduce( begin(iota_vec), end(iota_vec), 0 )<<endl;

    //  fill() & fill_n(): assignes the given value to all the elements in the range & till particluar index using fill_n()
    fill( begin(iota_vec), end(iota_vec), 3 );
    printVec();
    auto begin_rest = fill_n( begin(iota_vec), 4, 3 );
    fill( begin_rest, end(iota_vec), 99 );
    printVec();
    iota_vec.clear();
    fill_n(back_inserter(iota_vec), 5, 42);
    printVec();

    //  generate():  it assigns the value returned from functor class 
    iota_vec.clear();
    iota_vec.resize(10);
    generate( begin(iota_vec), end(iota_vec), gen_n());
    iota_vec.clear();
    iota_vec.resize(10);
    generate_n( back_inserter(iota_vec), 10, gen_n() );
    printVec();
    return 0;
}