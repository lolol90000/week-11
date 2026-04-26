#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    string title;
    int pages;

public:
    Book()
    {
        title = "Untitled";
        pages = 0;
    }

    void setInfo(string t, int p)
    {
        title = t;
        pages = p;
    }

    void printInfo()
    {
        cout << "Title: " << title << endl;
        cout << "Pages: " << pages << endl;
    }
};

int main()
{
    Book b1;

    b1.printInfo();

    b1.setInfo("C++ Basics", 250);

    b1.printInfo();

    return 0;
}