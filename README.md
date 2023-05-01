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


