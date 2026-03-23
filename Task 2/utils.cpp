#include "utils.h"   
#include <iostream> 

using namespace std;

void Swap(int& a, int& b) {
    int c = a;
    a = b;
    b = c;
    cout << a << ' ' << b << endl;
}