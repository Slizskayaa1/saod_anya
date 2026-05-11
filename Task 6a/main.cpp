#include <iostream>
#include "Str.h"

using namespace std;

int main()
{
    Str s("abracadabra");

    cout << s.find("abra", 0) << endl;
    cout << s.find("abra", 1) << endl;
    cout << s.find("cad", 0) << endl;
    cout << s.find("", 0) << endl;
    cout << s.find("bra", 8) << endl;
    cout << s.find("xyz", 0) << endl;

    Str a("hello");
    Str b("world");

    a += b;

    cout << (const char*)a << endl;

    return 0;
}