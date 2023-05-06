#include <iostream>
#include <bitset> 
using namespace std;

/*
- inherited form c
- provided in <bitset>
- its a templated type
- parameter is no of bits
*/
int main()
{
    bitset<8> b1{"10101110"};//initialise from string bitset with value 174
    bitset<8> b2{0xae};//initialise from integer (decimal or hexadecimal)
    bitset<8> b3{0b1010'1110};//initialise from binary constant
    bitset<8> b4{020};

    cout<<"b1: "<<b1<<endl;
    cout<<"b2 in decimal: "<<b2.to_ulong()<<endl;
    cout<<"b2 as string: "<<b2.to_string()<<endl;
    cout<<"b3: "<<b3<<endl;//works with iostream
    cout<<"b3 in decimal: "<<b3.to_ulong()<<endl;//works with iostream
    cout<<"b4 in decimal: "<<b4.to_ulong()<<endl;
    cout<<"b1 has "<<b1.size()<<" bits"<<endl;

    //display all bits
    for(size_t i=0; i<b1.size(); ++i)
    {
        cout<<b1[i]<<" ";
    }cout<<endl;

    try{
        cout<<"bound checking: "<<endl;
        // cout<<b1.test(8)<<endl;
        cout<<boolalpha<<b1.test(7)<< noboolalpha << endl;
    }catch(std::out_of_range& ex){
        cout<<"out of range: "<<ex.what()<<endl;
    } catch(...) {
        cout<<"unknown exception"<<endl;
    }

    // and or << >> operations
    bitset<8> b5{"0001"};cout<<"b5: "<<b5.to_ulong()<<endl;
    cout<<"~b5: "<<(~b5).to_string()<<endl;
    cout<<"b5 * 2: "<<(b5 << 1).to_ulong()<<endl;
    cout<<"b5 * 4: "<<(b5 << 2).to_ulong()<<endl;

    /*bitset operations*/
    bitset<8> b6{"11111111"}, b7{"00000000"};cout<<"b6: "<<b6<<" & b7: "<<b7<<endl;
    auto b8 = b6; auto b9 = b7;
    //reset
    // cout<<"reset(): "<<b6.reset()<<endl;
    // cout<<"reset(7): "<<((b6.test(7))?b6.reset(7):0)<<endl;
    
    //set
    // cout<<"set(): "<<b7.set()<<endl;
    // cout<<"set(7): "<<b7.set(7)<<endl;

    //flip
    // cout<<"flip(): "<<b9.flip()<<endl;
    // cout<<"flip(7): "<<b9.flip(7)<<endl;

    /*bitset checks*/
    //all: return true if all bits are set
    //any: return true if atleast one bit is set
    //none: return true if none bits are set
    cout<<"b7: "<<b7<<" none(): "<<boolalpha<<b7.none()<< noboolalpha<<endl;
    cout<<"b6: "<<b6<<" count(): "<<b6.count()<< endl;
    cout<<"b6: reset(7): "<<b6.reset(7)<<" count(): "<<b6.count()<< endl;
    return 0;
}