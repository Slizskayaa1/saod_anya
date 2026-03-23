#include <iostream>
#include <bitset>

using namespace std;

void Swap(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
	cout << a << ' ' << b << endl;
}

void rotate(int a[], int n) {
	int x = a[0];
	for (int i = 1; i < n; i++)
		a[i - 1] = a[i];
	a[n - 1] = x;
}

int len(const char* s) {
	int count = 0;

	for (int i = 0; s[i] != 0; i++) {
		count++;
	}
	
	return count;
}

int compare(const char* s, const char* t) {
	if (len(s) < len(t))
		return 1;
	else if (len(s) > len(t))
		return -1;
	else
		return 0;
}

int main() {
	/*int x = 3;
	int* p = &x;
	cout << x << ' ' << *p << ' ' << p << endl;

	p++;

	cout << p << endl;

	cout << p - &x << endl;

	typedef unsigned char byte; 	
	byte* pb = (byte*)--p;		
	for (byte* pt = pb; pt - pb < sizeof(int); pt++)
		cout << (int)*pt << ' ';	
	cout << endl;*/
	
	/*int a = 3, b = 5;

	cout << a << ' ' << b << endl;

	Swap(a, b)*/;

	int a[5]{ 1,2,3,4,5 };
	for (int i = 0; i < 5; i++)
		cout << a[i] << ' ';
	cout << endl;

	for (int* p = a; p - a < 5; p++)
		cout << *p << ' ';
	cout << endl;

	char str[] = "Hello!";
	cout << str << endl;

	cout << strlen(str) << ' ' << sizeof(str) << endl;

	char t[32];
	for (char* pd = t, *ps = str; *pd++ = *ps++;);

}

