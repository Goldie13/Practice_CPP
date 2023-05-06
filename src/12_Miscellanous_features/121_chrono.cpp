#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::literals;
using namespace std::chrono;

long long fibonacci(long long n)
{
    return ((n<2)?n:fibonacci(n-1)+fibonacci(n-2));
}

int main()
{
    seconds s;cout<<"Undefined value: "<<s.count()<<endl;

    auto hour = 5h;
    auto mins = 30min;
    auto sec  = 100s;
    auto msec = 1000ms;
    auto usec = 1000000us;
    auto nsec = 10000000000ns;

    cout<<"hour: "<<hour.count()
    <<"mins: "<<mins.count()
    <<"sec: "<<sec.count()
    <<"msec: "<<msec.count()
    <<"usec: "<<usec.count()
    <<"nsec: "<<nsec.count()<<endl;


    // sec s = 2; //implicit conversion from int not allowed
    seconds s1 = 2s; //Ok

    //but implicit conversion between durations is allowed
    seconds s2 = 1h; cout<<"s2 from hours: "<<s2.count()<<endl;
    milliseconds ms1 = 1s; cout<<"ms1 from seconds: "<<ms1.count()<<endl;

    //but
    // hours h = 100s;//Error! not ok data lost

    seconds s3 = duration_cast<seconds>(5043ms);//truncated to 5s
    seconds s4 = duration_cast<seconds>(-5013ms);//truncated to 5s
    cout<<"s3: "<<s3.count()<<" & s4: "<<s4.count()<<endl;

    //chrono clocks & ticks
    auto start = steady_clock::now();
    long long n = fibonacci(45);
    cout<<"fibonacci no is: "<<n<<endl;
    auto finish = steady_clock::now();
    auto elapsed = duration_cast<milliseconds>(finish - start);
    cout<<"Time taken: "<<elapsed.count()<<" msec"<<endl;

    //sleep_for()
    cout<<"Waiter!"<<endl;
    this_thread::sleep_for(2s);
    cout<<"coming sir!"<<endl;
    return 0;
}