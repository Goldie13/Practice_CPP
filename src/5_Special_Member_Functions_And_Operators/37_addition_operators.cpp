#include <iostream>
using namespace std;

class Complex
{
    double m_real;
    double m_imag;

    public:
    Complex(double real, double imag)
    : m_real(real), m_imag(imag){}
    friend Complex operator+(const Complex& complex);
    
    Complex& operator+=(const Complex& comp2)
    {
        this->m_real += comp2.m_real;
        this->m_imag += comp2.m_imag;
        return *this;
    }

    void print()
    {
        cout << m_real<<" + "<<m_imag<<"i"<<endl;
    }
};

Complex operator+(const Complex& comp1, const Complex& comp2)
{
        Complex lhs{comp1};
        lhs += comp2;
        return lhs;
}

int main()
{
    Complex comp1{3.2,2.4};
    Complex comp2{4.2,5.6};
    Complex comp3 = comp1 + comp2;
    comp3.print();
    return 0;
}