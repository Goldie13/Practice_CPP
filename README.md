# Practice_CPP


containers      |        type      |      use      | o(n)
-------------   | ---------------  | ------------- | ----------
string & vector | seq              | ------------- | add/remove elements in middle is fast. single memory clock for all element. Vector is the default choice to use for searching, random access & memory. cant add items in front.        
forward_list    | seq              | Singly LS     | ----------
list            | seq              | Doubly LS. when add or remove elements more frequently. accessing element is slower than vector   | - defined in \<list> no indexing/subscript. use more mem  to store than lists. lists does not support random access. one memory block per element. more slower tha vector & deque & use more memory but faster in adding / removing items in front provided searching is not involved
deque | seq | similar like vector but elements can be added in front efficiently | - defined in \<deque> more memory blocks with each store elements. similar to vector unlike when no sufficient memory is present then new memory block is formed instead of copy like vector. Its slightly slower than vector but faster to add/remove items in front. 
tree | associative | -------- | operations are very fast. no memory is allocated & released. only one other element is modified. no elements are moved around. finding element is very fast.
set | associative | |- defined in \<set> - unsorted collection of data -  elements consists only key which must be hence no duplicates - sets are stored in order - by default \< operator is used - for efficiency, implemented as tree (red black tree) - elements are const & applying algorithm has restrictions - very fast at accessing arbitary element - insertion & deletion is very - tree has to balanced - eg services allows access to check the usernames & if not in sets then return false - to remove duplicates - eg: read document: distinct words in set
map | associative |- Very fast accessing arbitarty element - insertion & deletion fast but tree should be balanced - very useful for indexed data - also useful to store data for file like json & xml  | - element has pair - key, values - keys needs to be uniques - same key two same values - key is used to locate data - eg map of companies staff: key: emp id; value: name of employee - key acts as index same like hashmap - tree structure - insert & remove like set - c++11 we can initialiser for inserting key value pair - supports transcripting but works differenctly from arrays & vectors - if element does not exist it will create, this overwrite the value
maps c++17 | associative | | - intruduced structured binding - easy to access data structures - declare variables, bind them to compound data structures & types ares deduced by the compiler
multiset & multimap | associative | | - sorted default ascending - similar to set & map except duplicate keys are allowed - does not support subscripting - Problem: it containes many matching elements & keys compared to unqiue keys of maps - as items are sorted all duplicate keys&values will be adjacent to each other - so it can have a iterator range - can be solved by find() & count() - lower_bound(k): returns iter to first element whose key is greater than or equal to k - upper_bound(k): returns iter to first element whose key is greater than k - lower_bound(k), upper_bound(k) defines half open range of iterators to all elements with key k - equal_range(): returns pair with first as lower & second as upper bound
hash_table | associative | | - unordered c++11 - uses hash-table instead of tree like map/set 
unordered (set, multiset, map, multimap) | associative | | - faster - reverse iterator not possible - will slow if hash is used - sorting we can populate into sort container
queue/priority queue | container adapter | - Network data packets waiting CPU - must be processed in sequence - can access only front item but if you want other item access use vector or map - PQ: networking; OS schedulers; out of band communication | - DS where items are stored in order - follow fifo - defined in \<queue> - no support for other containers - PQ: std queue with strictly in arrival order - PS similar to queue - PQ: it orders the items with most priority in the front & least at back - PQ: if two items have equal priorities by default queue doesnt order them by arrival time - PQ implemented using vector or deque - same member functions like queue - push(1,3,5,2) into PQ it will populate PQ as 5,3,2,1 highest -> lowest priority - PQ: Only top() can be accessed - PQ: same order is not quaranteed in same priority instead nested maps 
stack | container adapter | - parsing expressions in compilers - checking unbalanced paranthesis - implementing undo functionality - storing history for back/forward buttons in web browser | - DS which stores items in order in which they are inerted - when new items inserted items are at top - only top is accessible - follows lifo - implemented using deque - interfaces similar to PQ

## Dervied class memory layout
- Derived class obj is stored in memory as a base class obj followed by derived class part
- when derived class obj is created, base class ctor is called first then derived ctor
- when destroyed derived dtor is called first & then base class dtor
- baseclass vehicle; child class aeroplane
- memory layout will be vehicle - aeroplane

## static vs dynamic type
- static type used in variable declaration
- int x{5};// static type int
- int* px = &x; // static type pointer to int
- Circle circle;// static type Circle
- Circle* pcircle = &Circle;// static type pointer to Circle
- Shape* pshape = &circle;// static type pointer to Shape
- Shape& rshape = circle;// static type reference to Shape

static      |        dynamic      |
-------------   | ---------------  |
| c++ always uses static typing | Only used for pointer or reference to a base class  |
| type checking done by compiler | compiler does not decide which function to call |
| less runtime overhead | more runtime overhead, member function is chosen at runtime using object in memory |
| better optimization | no optimization |
| static binding | dynamic binding: - reference or pointer to base class has to be used - member function was declared virtual in the base class |

override      |        overload      |
-------------   | ---------------  |
same signature as parent | different signature from parent |
doesnt stop dynamic binding | prevents dynamic binding |
NA | may hide parent member function |
introduced in c++11 | NA |

### final keyword
- introduced in c++11
- final class cannot be derived from
- final member function cannot be overridden in a child class
- libraries often use "final"
- library can provide class heirarchy or use one internally
- users of the library cannot extend this class heirarchy

### Virtual dtors
- child object is stored in memory as a parent object followed by the child part
- Shape* c = new circle; //created a obj in heap
- delete c;// releasese memory; calls destructor
- it calls shape dtor due to static binding if dtor is not virtual in base class
- if we do not define destructor, compiler will synthesize for us which is not virtual by default
- if we use pointer to base, that means derived part of object is not destroyed:memory leaks; resource leaks; undefined behaviour

### Abstract base class (Interface in other languages)
- a class with pure virtual member functions
- we derive from an abstract base class, we must override all its pure virtual functions
- otherwise our derived will also be virtual class 

### Virtual functions implementation
- member functionsa are not stored in object
- they are implemented as global functions
- when they are called, pointer to object is passed as an extra argument called "this"
- when compiler encounters class which has virtual member function it creates & populates data structure
called as vtable
- when compiler sees call to virtual function it generates some extra code:
    - this code is executed at runtime
    - it checks dynamic type of the object
    - it uses vtable to call correct version of the function
- vtable stores the addresses of all member functions of the class which are decalared virtual
- vtable is array of pointers to member functions
- each virtual member function is identified by an index into the table
- when virtual function is called compiler replaces names of the function by corresponding index in the table
- runtime code will 
    - determine object's dynamic type
    - locate the vtable for that dynamic type
    - look up the element in the vtable
    - deference the function pointer & call it

### Polymorphism
- "many forms"
- different types with same interface (programming language): they have the same behaviour
- STL containers are an eg of polymorphism
    - vector\<int> is different type from vector\<string>
    - they have same interface regardless of type
    - this parameteric polymorphism because element is the type (compile time)
    - subtype polymorphism is dynamic binding (runtime)
- advantages: avoids duplicate code; saves programmer time; ensures correct behaviour; code resuse

### where to handle errors:
- we should not mix up GUI with network code
- error handling code is a distraction from 
- if uncaught exception is not handled by any of the catch blocks after the try block program will try to find one in the "enclosing scope"
- if it doesnt find one, it will jump out of current function & look for a handler in functions caller
- if it does still not find one, it jumps to that functions caller & so on
- if there is no suitable handler, the program terminates
- when exception is thrown, several things happen:
    - thrown object is copied into special area of memory
    - area is setup by compiler
        - area is accessible by any catch block which can handle object type
        - every local variable in scope is destroyed
            - including the original thrown object
    - program immediately leaves the scope
        - it doesnt execute any further instructions of any type
    - stack unwinfing:
        - program will look for catch that can handle exception
        - if it cannot find one, it will immediately destroy all local vars & exit the current scope
        - it then looks enclosing scope
        - this continues untill it finds suitable handler
            - it reaches main() without finding one, program calls std::terminate()
        - process of repeatedly destroying local vars exiting the current scope is called "stack unwinding"

### std::exception heirarchy
- c++ defines std::exception class
- base class for an inheritance heirarchy
    - consistent interface for exception objects
    - enables polymorphism - reduces no of handlers needed
- exception
    - bad_alloc
    - bad_cast
    - logic_error
        - out_or_range
        - domain_error
        - invalid_argument
        - length_error
    - runtime_error
        - overflow_error
        - underflow_error
        - range_error

- defines 5 public member functions
    - ctor
    - copy ctor
    - assignment operator
    - virtual member function what()
    - virtual dtor
- sub classes:
    - bad_alloc
        - thrown when memory allocation fails
    - bad_cast
        - thrown when dynamic cast fails
    - logic_error
        - parent class for error conditions resulting from fault logic
    - runtime_error
        - parent class for error conditions beyond programs control
    - out_of_range
        - attempt to access item outside range
        - vector.at(i)
    - invalid_argument
        - arguemnt to function is not accpetable
        - eg passing non numeric to stoi()
    -  domain_error
        - argument to function is outside domain of application values
        - eg invalid date field
    - length_error
        - length limit of an obj is exceeded
        - eg appending too many elements to a string
    - overflow_error
        - result of computation is too large for the result var
    - underflow_error
        - result of floating point computation is too small for result var
    - range error
        - internal computation gives value which cannot be represented by result var

### throw()
- c++98 provided throw() exception specifier
- this comes after function parameter list
- eg void function() throw(){ }
- if function throws exception which is not in the list, program is immediately terminated
- void function() throw() { }: indicates that the function does not throw any exceptions
- problem with throw():
    - exceptions is not checked by the compiler
    - list of exceptions is incorrect, program may be terminated unexceptedly
- throw() removed from language & replaced by "noexcept"
    - was depreciated in c++11
    - throw(arg) removed in c++17
    - throw() removed in c++20

### noexcept keyword
- equivalent to throw()
- introduced in c++11
- if exception is thrown, program terminates immediately
- noexcept is a promise to caller that function will not throw any exception
- noexcept function guarantees no throw 
- helpful to write exception safe code which calls the function
- adv:
- helps compiler generate better optimized code
    - more info about how code behaves
    - not required to generate code for "stack unwinding"
- modern c++ has optimized versions of some operators
    - these are not intrinsically exception safe
    - std lib algo will only use these operators if they are declared noexcept
    - otherwise they will call non optimized versions which are slower
- noexcept to be used possible
    - if we are certain a function will not throw any excpetions
    - we cannot do anything when exception is thrown (automatic termination)
    - egs std::swap() & dtors
- if virtual function is noexcept in base then override in derived class will also be noexcept
- inheriting ctors will be noexcept if base ctor is noexcept
- synthesized member function is noexcept if base version is noexcept
- dtors are implicitly noexcept including base class dtor & all members of class dtor

#### std::swap()
- sort() internally uses swap()
- its noexcept specified
- consist copy as temporary obj or value to swap obj or values
- we write custom swap function using std::swap making it inline so compiler will optimize it which avoid call to copy ctor & assignment operator
- ctor & copy ctor are strong exception guarantee
- dtor is also no throw guarantee (noexcept)
- assignment can also be strong exception guarantee if used properly
- we can std::swap in assignment opertor to avoid memory leak as swap is noexcept / no exception guarantee
- this is called "copy-and-swap" idiom

### RULE OF FIVE
- c++11 rule of three becomes rule of 5
- if a class needs to implement a dtor to function properly then pr0bably needs to implement copy & move operators as well
- eg: class which allocates memory with new in its ctor
    - dtor to call "delete" when objects are destroyed
    - copy ctor to perform a deep copy when copying 
    - assignment operator to perform deep copy 
    - move operators to set argument's pointer to nullptr

### Rule of Zero
- if class does not decalre dtor then it does not need to declare copy or move operator either
- for most classes rule of "zero" is sufficient
    - do not declare any special member functions
    - compiler synthesized defaults will be sufficient
- compiler will also synthesize a default ctor
    - unless we declare one ourselves
    - sometimes useful to declare a default ctor which initializes the members with sensible values

### Rule of Three / Five
- if we need dtor eg release a resource then compiler generated copy/move operator will not be correct
- in this case, we need to provide our own:
    - dtor
    - copy ctor
    - copy assignment operator
- we will probably need to provide a ctor as well eg to allocate memory
- for performance, we should also add move operators
otherwise copy operators will be used
- Move only class:
    - sometimes we need to declare dtor but dont want to copy the obj
        - eg: class which manages network connection
        - dtor closes connection
        - we do not want to create duplicate of the     connection
        - in this case, make the class make-only
- Immovable class:
    - we can make class immovable and uncopyable
        - obj of this class cannot be passed to a function
        - obj of this class cannot be returned by a function
        - eg low level concurrency objects which release lock at the end of their scope
    - to do this, delete the copy operators
        - compiler will not synthesize the move operators
        - any copy or move operation will invoke copy operators which are deleted

### function arguments and move semantics
- pass by value
    - copy ctor called
    - function has its own of callers object
    - caller's obj is unmodified
    - lvalue obj passed: 2 copies
    - rvalue obj passed: 1 move + 1 copy
- pass by const ref
    - function has read only access to callers object
    - callers object is unmodified
- pass by non const ref & pass by address
    - function has full access to callers object
    - callers obj may be modified
- pass by move
    - move ctor is called
    - function now owns caller obj data
    - callers obj is unusable (until reassigned)

### Relative costs:
- pass by const ref
    - lvalue obj passed: 1 copy
    - rvalue obj passed: 1 copy
- pass by value / pass by move
    - lvalue obj passed: 2 copies
    - rvalue obj passed: 1 move + 1 copy
- pass by value then move:
    - lvalue obj passed: 1 copy + 1 move
    - rvalue obj passed: 2 moves
- pass by rvalue ref:
    - lvalue obj passed: not allowed
    - rvalue obj passed: 1 move

### forwarding references
- programmers cannot directly create a nested reference
    - int&& x = y; // error
- however this compiler can do this internally for a type alias or template parameter
    - using int_ref = int&
    int i{42};
    int_ref j{i};//j ref to i
    int_ref& rj{j};// rj ref to (ref to int)
- type of result is determined  by "reference collapsing"
- reference to ( reference to int ) "collapses" into ref to int

### reference collapsing rules
- rvalue ref's can also appear in nested ref's
- result is rval ref only if both are rval ref's
    using lval_ref = int&
    using rval_ref = int&&

    lval_ref& ---> int&
    lval_ref&& --> int&
    rval_ref& ---> int&
    rval_ref&& --> int&&

### template argument reference
- && has complete diff effects if the args is generic
    template\<tynename T>
    void func(T&& obj)

    - obj is now forwarding ref
    - it can be bound to rval or lval 
- template argument deduce
    - if lval is passed then 
        Test&& --> Test& as per collapsing rules for ref's
    - if rval is passed then 
        Test&& --> Test&&

### applications of perfect forwarding
- eg make_pair
- if passed is rval, then move ctor is called automatically
- it is used by variadic templates to dispatch their arguments to functions which process them
    - retains information whether the passed obj was an lval or rval

### std::forward()
- casts its args to rval ref
    - std::forward\<T>(x); // = static_cast<T&&>(x)
- if x is type T&, it will be left as lval to rval ref to T
- if x is type T or T&&, it will be cast to an rval ref to T
- forward does not cast its arg if its lval ref
- forward requires parameter; move does not
