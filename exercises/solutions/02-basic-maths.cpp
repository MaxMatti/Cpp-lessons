#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;

// basic maths
void task_2a(int a, int b) {
	cout << a + b << "\n";
	cout << a - b << "\n";
	cout << a * b << "\n";
	cout << a / b << "\n";
	cout << a % b << "\n";
}

// faculty
int task_2b(int a) {
	int c = 1;
	for (int i = 0; i < a; ++i) {
		c *= (i + 1);
	}
	return c;
}

// integer overflow
int task_2c(short int a, short int b) {
	short int c = a * b;
	return max(max(a, b), c);
}
// follow-up: why is this not always c?
// example: 2 and 16386

// floating point precision
bool task_2d(float a, float b) {
	return a * b / b == a;
}
// follow-up: why is this not always true?
// example: 1/3 and 1/81

// floating point: infinity
float task_2e() {
	float a = 2;
	float b = 1;
	while (a != b) {
		b = a;
		a *= 2;
	}
	return a;
}

// xor using and, or
bool task_2f(bool a, bool b) {
	return (a && !b) || (!a && b);
}

int main() {
	cout << "\nTask 2a:\n";
	task_2a(10, 10);
	cout << "\nTask 2b:\n";
	task_2b(10);
	cout << "\nTask 2c:\n";
	task_2c(10, 10);
	cout << "\nTask 2d:\n";
	task_2d(10., 10.);
	cout << "\nTask 2e:\n";
	task_2e();
	cout << "Done.\n";
	return 0;
}
