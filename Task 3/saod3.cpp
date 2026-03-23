#include <iostream>;
#include <cmath>
#include "Complex.h"

using namespace std;

int main()
{
    Complex a(1.0, 2.0), b = 3;
    cout << a << ", " << b << endl;
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;

    Complex v[4]{ 1, 2, Complex(2, 3) };
    
    for (int i = 0; i < 4; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    
    Complex w[4]{ 1, 2, Complex(2, 3), Complex(4, 5) };
    
    for (int i = 0; i < 4; i++) {
        cout << w[i] << " ";
    }
    cout << endl;
}
    

