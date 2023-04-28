#include <iostream>
#include <cstdlib> //for srand or rand old c++
using namespace std;

int main()
{
    //  srand
    srand(time(0)); //seed as current time

    //  simple way
    for(auto i=0; i<3; ++i)
    {
        cout<<rand()<<" "; //predictable
    }cout<<endl;

    //  more complex
    cout<<endl;
    for(auto i=0; i<3; ++i)
    {
        cout<<(0.1*rand()/RAND_MAX)<<" "; //predictable
    }cout<<endl;

    //  more complex
    cout<<endl;
    for(auto i=0; i<3; ++i)
    {
        cout<<(99*rand()/RAND_MAX+1)<<" "; //predictable
    }cout<<endl;

    /* Random numbers engines in modern c++
    - default_random_engine
        - implementatiion defined
        - may be wrapper around rand() implementation
    - mt19937
        - "Mersenne Twister" with period of 2^19937-1
        - very fast at generating numbers
        - almost cypto secure
        - has lot of state
        - usually best choice for most reuqirements
    */
}