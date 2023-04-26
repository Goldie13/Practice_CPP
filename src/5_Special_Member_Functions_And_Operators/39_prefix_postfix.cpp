#include <iostream>
using namespace std;

class Complex
{
    double m_real;

    public:
    Complex(double real)
    : m_real(real){}
    
    Complex& operator++() //prefix
    {
        ++this->m_real;
        return *this;
    }
    Complex& operator--() //prefix
    {
        --this->m_real;
        return *this;
    }

    Complex operator++(int) //postfix
    {
        //take a copy
        Complex obj_complex{*this};
        ++m_real;
        return obj_complex;
    }

     Complex operator--(int) //postfix
    {
        //take a copy
        Complex obj_complex{*this};
        --m_real;
        return obj_complex;
    }
    void print()
    {
        cout << m_real<<endl;
    }
};

int main()
{
    Complex comp1{3};
    Complex comp2{4};
    cout<<"comp1 real: ";comp1++.print();//temp:3; real:4
    cout<<"\ncomp2 real: ";comp2++.print();//temp:4; real:5
    cout<<"comp1 real: ";++comp1; comp1.print();//real:5
    cout<<"\ncomp2 real: ";++comp2; comp2.print();//real:6
    cout<<endl;
    // cout<<"real: postfix: ";comp1.m_real;cout<<"\ncomp2 real: ";comp2.print();cout<<endl;
    return 0;
}