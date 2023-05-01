#include <iostream>
#include <map>
using namespace std;

class book
{
    private:
        string m_title;
        string m_publisher;
    public:
        book(string title, string publisher)
        : m_title(title), m_publisher(publisher){}

        friend ostream& operator << (ostream& os, const book& bk)
        {
            os << " ( " <<bk.m_title<<" , "<<bk.m_publisher<<" ) ";
            return os;
        }
};

int main()
{
    multimap<string, book> library;

    //add
    book prog_princs1("book1", "pub1");
    library.insert({"author1",prog_princs1});

    book prog_princs2("book2", "pub2");
    library.insert({"author2",prog_princs2});

    book prog_princs3("book3", "pub3");
    library.insert({"author3",prog_princs3});

    book prog_princs4("book4", "pub4");
    library.insert({"author4",prog_princs4});

    for(auto b : library)
    {
        cout<<b.first<<" , "<<b.second<<endl;
    }
    return 0;
}