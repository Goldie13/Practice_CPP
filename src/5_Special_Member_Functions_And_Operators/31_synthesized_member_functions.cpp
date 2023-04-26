/* Rule of 3 of class
- copy ctor
- assignment operator
- dtor
*/
#include <iostream>
using namespace std;
using namespace std::literals;
class test
{
    public:
    char* m_data;
    int m_size;

    //ctor
    test(const string& data) : m_size(data.size()) 
    {
        cout<<"ctor"<<endl;
        m_data = new char[m_size];//heap memory
        for(auto i=0; i<m_size; ++i)
        {
            m_data[i] = data[i];
        }
    }

    //synthesized member functions
    //test(const test& other) : m_data(other.data), m_size(other.size){}
    //test& test::operator=(const test& other) { m_data = other.data; m_size = other.size; return *this;}

    //explicit ctor
    //comment this to see effect of shallow copy
    test(const test& other) : m_size(other.m_size)
    {
        cout<<"explicit copy ctor"<<endl;
        m_data = new char[m_size];//deep copy
        for(auto i=0; i<m_size; ++i)
        {
            m_data[i] = other.m_data[i];
        }
    }

    //explicit assignment operator
    //comment this to see effect of shallow copy
    test& operator=(const test& other)
    {
        //check wether this pointer & other pointer are same
        //if yes, just return *this

        if (&other != this) {
            // if this & other are not equal
            // then delete data
            //  assign new value to data
            delete[] m_data;
            m_data = new char[other.m_size];
            for (auto i = 0; i < m_size; ++i)
            {
                m_data[i] = other.m_data[i];
            }
        }
        return *this;
    }

    //dtor
    ~test()
    {
        cout<<"calling dtor"<<endl;
        delete[] m_data;
    }

    int length()
    {
        return m_size;
    }
};

int main()
{
    test test1{"Anosh"s};//ctor; test1 has data into heap memory for addr like 0x100
    test test2{"Ingles"s};//ctor; test2 has data into heap memory for addr like 0x200
    test test3{test2};//synthesized copy ctor; test3 points to data of test2 ie 0x200
    test test4{"test4"};//ctor; test4 has data into heap memory for addr like 0x400

    cout<<"test2 size: "<<test2.length()<<endl;
    cout<<"test3 size: "<<test3.length()<<endl;
    cout<<"test1 size: "<<test1.length()<<endl;

    //dtor for test3 which deletes data of test2 0x200
    //dtor for test1 which delete data of 0x100
    //aborts as dtor will try to destroy test2 which is already destroyed

    // THIS IS SHALLOW COPY
    // CAN BE RECTIFIED by EXPLICIT copy ctor / Deep copy

    test4 = test2;//synthesized assignment operator member function is called
    //data is used by both test2 & test4
    cout<<"test4 size: "<<test4.length()<<endl;

    //dtor for test4 which deletes data of test2 0x200
    //dtor for test3 which delete data of 0x300
    //dtor for test1 which delete data of 0x100
    //aborts as dtor will try to destroy test2 which is already destroyed

    // THIS IS SHALLOW COPY
    // CAN BE RECTIFIED by EXPLICIT assignment operator function

    //if we implement ctor explicity compiler will not synthesize default / empty constructor
     
    return 0;
}