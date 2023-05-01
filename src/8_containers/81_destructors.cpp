#include <iostream>
using namespace std;

class Shape
{
    public:
        virtual void draw() const { cout<<"Shape draw"<<endl; }
        virtual ~Shape(){ cout<<" Shape Dtor "<<endl; }
        // virtual ~Shape() = default; //modern c++11
};

class Circle : public Shape
{
    public:
        void draw() const { cout<<"Circle draw"<<endl; }
        ~Circle(){ cout<<" Circle Dtor "<<endl; }
};


int main()
{
    Shape* b = new Shape(); 
    b = new Circle();
    b->draw();
    
    delete b;// memory leak as only shape dtor is called
    // but due to dynamic binding Circle obj is allocated memory
    // to fix it define virtual dtor in base class : shape
    // Circle (child ) dtor & then Shape (base) dtor
    
    return 0;
}