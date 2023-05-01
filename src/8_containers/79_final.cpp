#include <iostream>
using namespace std;

class Shape
{
    public:
        virtual void draw()const;
};

// class Circle final : public Shape
class Circle : public Shape
{
    public:
        void draw() const override;
        // void draw() const override final;
};

class DeluxeCircle : public Circle
{
    public:
        void draw() const override; // Error! overriding final function
};

int main()
{

    return 0;
}