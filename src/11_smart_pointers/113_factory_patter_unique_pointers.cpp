#include <iostream>
#include <memory>
using namespace std;

class Shape
{
    public:
        virtual void draw() = 0;
};

class Circle : public Shape
{
    public:
        void draw() { cout<<"Circle"<<endl; }
};

class Triangle : public Shape
{
    public:
        void draw() { cout<<"Triangle"<<endl; }
};

class Square : public Shape
{
    public:
        void draw() { cout<<"Square"<<endl; }
};

int main()
{
    int option = 0;
    
    while(option != 4 )
    {
        cout<<"choose 1. Circle 2. Triangle 3. Square 4. Exit:"s;
        cin>>option;
        switch (option)
        {
        case 1:
        {
            std::unique_ptr<Shape> pShape{make_unique<Circle>()};
            pShape->draw();
            break;
        }
        case 2:
        {
            std::unique_ptr<Shape> pShape{make_unique<Triangle>()};
            pShape->draw();
            break;
        }
        case 3:
        {
            std::unique_ptr<Shape> pShape{make_unique<Square>()};
            pShape->draw();
            break;
        }
        case 4:
        default:
            break;
        }
    }
    return 0;
}