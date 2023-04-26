#include <iostream>
#include <string>
using namespace std;

class student
{
    string m_name;
    int m_id;

    public:
    student(string name, int id)
    : m_name(name), m_id(id){}
    friend bool operator==(const student& lhs, const student& rhs);
    friend bool operator!=(const student& lhs, const student& rhs);
    friend bool operator<(const student& lhs, const student& rhs);

    void print()
    {
        cout << m_name<<" : "<<m_id<<endl;
    }
};

bool operator==(const student& lhs, const student& rhs)
{
    if(lhs.m_id == rhs.m_id)
        return true;
    return false;
}

bool operator!=(const student& lhs, const student& rhs)
{
    return !(lhs == rhs);
}

bool operator<(const student& lhs, const student& rhs)
{
    return (lhs.m_id < rhs.m_id);
}

int main()
{
    student s1{"A", 10};
    student s2{"B", 20};
    student s3{"A", 10};

    cout<<boolalpha;
    cout<<"s1 == s2 : "<<(s1==s2)<<endl;
    cout<<"s2 == s3 : "<<(s2==s3)<<endl;
    cout<<"s1 == s3 : "<<(s1==s3)<<endl;

    cout<<"s1 < s2 : "<<(s1<s2)<<endl;
    cout<<"s2 < s3 : "<<(s2<s3)<<endl;
    cout<<"s1 < s3 : "<<(s1<s3)<<endl;

    //for sorting of container < operatpr is used
    // < operator of the elements will be used to determine the order
    return 0;
}