#include <iostream>
#include <array>
#include <random>
#include <algorithm>
using namespace std;

namespace constants{
    const int npegs = 4;
    const int nturns = 10;
    const int ncolours = 3;
}

using peg_array = std::array<char, ::constants::npegs>;
using colour_array = std::array<char, ::constants::ncolours + 1>;

namespace constants {
    const colour_array colours = { 'R', 'G', 'R' };
}

//populate
peg_array populate()
{
    peg_array code{0};
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> idist(0, ::constants::ncolours-1);
    generate( begin(code), end(code), [&](){
        auto i = idist(mt);
        return ::constants::colours[i];
    } );
    return code;
}

//normalize
string normalize(const string& s)
{
    string retVal{""};

    copy_if( cbegin(s), cend(s), back_inserter(retVal), [](char c){
        return isalpha(c);
    } );

    transform( begin(s), end(s), begin(retVal), [](char c){
        return toupper(c);
    } );

    return retVal;
}


//get input
peg_array get_input()
{
    string input{" "}, normal{" "};
    peg_array result{" "};
    do{
        cout<<"Enter  "<<::constants::npegs<<" characters ( ";
        for( auto c: ::constants::colours )
            cout << c;
        cout<< " ) "<<endl;
        getline(cin,input); 
        normal = normalize(input);
    } while( normal.size() != ::constants::npegs );

    for( int i=0; i<normal.size(); ++i )
    {
        result[i] = normal[i];
    }
    return result;
}

//exact matches
int exact_matches( const peg_array& guess, const peg_array& solution )
{

    peg_array matches;
    transform( begin(guess), end(guess), begin(solution), begin(matches), [](const char c1, const char c2){
        return (c1 == c2) ? c1 : '\0';
    } );

    return count_if( begin(matches), end(matches), [](const char c){
        return ( c != '\0' );
    } );
}

//loose matches
int loose_matches( const peg_array& guess, const peg_array& solution )
{
    string copy_guess{0};
    int count{0};

    copy( begin(guess), end(guess), back_inserter(copy_guess) );

    for(auto colour = begin(solution); colour !=  end(solution); ++colour)
    {
        auto it = find_if( begin(copy_guess), end(copy_guess), [=](const char c){
            return c == *colour;
        } );

        if(it != end(copy_guess)){
            ++count;
            copy_guess.erase(it);
        }
    }

    return count;
}

int main()
{
    peg_array pegs = populate();
    auto printPegArray = [&](const auto& pegs){
        for_each( begin(pegs), end(pegs), [&](const auto i){
            cout<<i;
        } );
    };

    bool winner{false};
    for( int i = 0; i < ::constants::nturns; ++i )
    {

        peg_array input = get_input();

        auto exact = exact_matches(input, pegs);
        auto loose = loose_matches(input, pegs) - exact;
        cout << exact <<" exact match(es) " << endl;
        cout << loose <<" near match(es) " << endl;

        if(exact == ::constants::npegs) {
            cout<< " You have found the correct solution! ";
            for( auto peg: pegs )
            {
                cout<<peg;
            }cout<<endl;
            
            winner = true;
            break;
        }

        if( false == winner ){
            cout<<" sorry! solution was:  "<<endl;
            for( auto peg: pegs )
            {
                cout<<peg;
            }cout<<endl;
        }
    }



    return 0;
}