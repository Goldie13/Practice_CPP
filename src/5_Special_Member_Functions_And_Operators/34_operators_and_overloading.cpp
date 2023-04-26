/*
useful operators to overload:
+
-
*
/
=
==
!=
<
()

operators should not overload
&&
||
&
,
::
. 
*
?:
*/
#include <iostream>
using namespace std;

class testclass
{
    public:
    int i;
    int j;
    testclass():i(2),j(2){}
    testclass operator+(testclass test)
    {
        testclass t3;
        t3.i = this->i + test.i;
        t3.j = this->j + test.j;        
        return *this;
    }
};
int main()
{
    testclass test1;
    testclass test2;
    testclass test3 = test1 + test2;
    cout<<"testclass.i : "<<test3.i<<" testclass.j: "<<test3.j<<endl;
    return 0;
}