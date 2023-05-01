#include <iostream>
using namespace std;

class shape
{
    public:
        virtual void draw() const { cout<<" drawing generic shape "<<endl; }
};

class circle : public shape
{
    public:
        // Step 3: Uncomment: This make sure to call virtual base function
        using shape::draw;
        // Step 1: comment below: It should call step 2 ideally but it gives error?
        // void draw() const override{ cout<<" Drawing a circle "<<endl; } //ok! override shape::draw()
        // Step 2: after comment step 1: function overloading hides virtual function in base
        // void draw(int radius) const override; //error doesnt override
};

int main()
{
    circle circle;
    circle.draw();
}