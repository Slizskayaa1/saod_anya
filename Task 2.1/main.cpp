#include <iostream>

using namespace std;

int main()
{
    char a = 0b01011001;
    signed char b = 0b10101001;
    short c = 0b0011001100100001;
    short d = 0b1101111110100011;

    cout << "01011010: " << a << endl;
    cout << "10111110: " << (int)b << endl;
    cout << "0011110110010001: " << c << endl;
    cout << "1110101001001110: " << d << endl;
}