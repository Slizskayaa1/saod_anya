#include <iostream>
#include "str.h"

using namespace std;

int main() {
    Str s = "Privet";
    Str ss = "Mir";

    cout << strlen(s) << endl;

    s += ss;

    cout << s << endl;


    return 0;
}