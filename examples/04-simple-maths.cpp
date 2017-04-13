#include <iostream>
using namespace std;

int main() {
	long int a = -5, b = 16;
	unsigned int c = a;
	long unsigned int d = a;
	short int e = c;
	long int f = e, g = c;
	cout << "a: " << a << "\n" "b: " << b << "\n";
	cout << "c: " << c << "\n" "d: " << d << "\n";
	cout << "e: " << e << "\n" "f: " << f << "\n";
	cout << "g: " << g << "\n";
	return 0;
}
