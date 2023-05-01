#include <iostream>
using namespace std;

class baseClass
{
private:
    int i{2};
    void privateBasePrint(){};

public:
    int j{4};
    void publicBasePrint(){};

protected:
    int h{5};
    void protectedBasePrint(){};
};

class derivedClassPublic : public baseClass
{
private:
    int x{4};
    void privateDerivedClassPublic()
    {
        publicBasePrint(); // public members accessible
        // privateBasePrint();//private members accessible
        protectedBasePrint(); // protected members accessible
    }

public:
    derivedClassPublic()
    {   
        //own private members
        cout<<x;
        privateDerivedClassPublic();

        //base members
        publicBasePrint(); // public members accessible
        // privateBasePrint();//private members accessible
        protectedBasePrint(); // protected members accessible
    }

    void printDerivedClassPublic(){cout<<"print in printDerivedClassPublic"<<endl;}
};

class derivedClassPublic2 : public baseClass
{
private:
    int x2{4};
    void privateDerivedClassPublic2()
    {
        publicBasePrint(); // public members accessible
        // privateBasePrint();//private members accessible
        protectedBasePrint(); // protected members accessible
    }

public:
    derivedClassPublic2()
    {   
        //own private members
        cout<<x2;
        privateDerivedClassPublic2();

        //base members
        publicBasePrint(); // public members accessible
        // privateBasePrint();//private members accessible
        protectedBasePrint(); // protected members accessible
    }

    void printDerivedClassPublic2(){cout<<"print in printDerivedClassPublic2"<<endl;}
};

class derivedClassPrivate : private baseClass
{
private:
    int y{4};
    void privatederivedClassPrivate() 
    {
        publicBasePrint();//public members accessible
        // privateBasePrint();//private members accessible
        protectedBasePrint();//protected members accessible
    }

public:
    derivedClassPrivate()
    {
        //own private members
        cout<<y;
        privatederivedClassPrivate();

        //base members
        publicBasePrint(); // public members accessible
        // privateBasePrint();//private members not accessible
        protectedBasePrint(); // protected members not accessible
    }
};

class derivedClassProtected : protected baseClass
{
private:
    int z{4};
    void privatederivedClassProtected() 
    {
        publicBasePrint();//public members accessible
        // privateBasePrint();//private members accessible
        protectedBasePrint();//protected members accessible
    }

public:
    derivedClassProtected()
    {
        //own private members
        cout<<z;
        privatederivedClassProtected();

        //base members
        publicBasePrint(); // public members accessible
        // privateBasePrint();//private members accessible
        protectedBasePrint(); // protected members accessible
    }
};

int main()
{
    //  base class obj
    baseClass b;
    // b.i;//private not accessible but only public members
    // b.privateBasePrint();//inaccessible as declared private
    cout << b.j;         // only public memebers as derived is inherited using access modifiers
    b.publicBasePrint(); // accessible as declared public
    // b.h;//as declared protected
    // b.protectedBasePrint();//inaccessible as declared proctected

    //derived class obj with public inheritance
    derivedClassPublic d_public;
    // d_public.x;//inaccessible as declared private
    // d_public.privateDerivedClassPublic();//inaccessible as declared private
    // d_public.i;//private in base
    // d_public.privateBasePrint();//private in base
    cout << d_public.j;         // public in base
    d_public.publicBasePrint(); // public in base
    // d_public.h;//protected in base
    // d_public.protectedBasePrint();//protected in base

    //derived class obj with private inheritance
    derivedClassPrivate d_private;
    // d_private.y;//inaccessible as declared private
    // d_private.privatederivedClassPrivate();//inaccessible as declared private
    // d_private.i;//private in base
    // d_private.privateBasePrint();//private in base
    // cout << d_private.j;//private inheritance
    // d_private.publicBasePrint();//private inheritance
    // d_private.h;//private inheritance
    // d_private.protectedBasePrint();//private inheritance

    //derived class obj with protected inheritance
    derivedClassProtected d_protected;
    // d_protected.z;//inaccessible as declared private
    // d_protected.privatederivedClassProtected();//inaccessible as declared private
    // d_protected.i;//private in base
    // d_protected.privateBasePrint();//private in base
    // cout << d_protected.j;//protected inheritance
    // d_protected.publicBasePrint();//protected inheritance
    // d_protected.h;//protected in base
    // d_protected.protectedBasePrint();//protected in base

    baseClass b_public = derivedClassPublic();
    // b_public.x;//inaccessible as declared private
    // b_public.privatederivedClassPublice();//inaccessible as declared private
    // b_public.i;//private in base
    // b_public.privateBasePrint();//private in base
    cout << b_public.j;         // public in base
    b_public.publicBasePrint(); // public in base
    // b_public.h;//protected in base
    // b_public.protectedBasePrint();//protected in base

    baseClass* b_ptr = &d_public;
    // b_ptr->printDerivedClassPublic();//not allowed

    // baseClass* b_ptr_2 = new derivedClassPrivate();//private inheritance
    // baseClass* b_ptr_3 = new derivedClassProtected();//protected inheritance

    // derivedClassPrivate* d_private_ptr = new derivedClassPrivate();
    // d_private_ptr = dynamic_cast<baseClass*>(b_ptr);

    // derivedClassProtected* d_protected_ptr = new derivedClassProtected();
    // // baseClass* b_ptr = dynamic_cast<baseClass*>(d_protected_ptr);

    // derivedClassPublic* d_public_ptr = new derivedClassPublic();
    // baseClass* b_ptr = dynamic_cast<derivedClassPublic*>(d_public_ptr); //allowed
    // b_ptr->printDerivedClassPublic();

    // derivedClassPublic2* d_public_ptr_2 = new derivedClassPublic2();
    // b_ptr = dynamic_cast<baseClass*>(d_public_ptr_2); //allowed

    return 0;
}