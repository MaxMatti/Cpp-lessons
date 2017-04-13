#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// hello world
void task_1a() {
	cout << "Hello World!\n";
}

// hello user
void task_1b() {
	cout << "Please enter your name: ";
	string name;
	cin >> name;
	cout << "Hello " << name << "!\n";
}

// iomanip
void task_1c() {
	cout << "Please enter the height: ";
	int height, width;
	cin >> height;
	cout << "Please enter the width: ";
	cin >> width;
	cout << "Height: " << setw(4) << height << "\n";
	cout << "Width:  " << setw(4) << width << "\n";
	cout << "Area:   " << setw(4) << height * width << "\n";
}

int main() {
	cout << "\nTask 1a:\n";
	task_1a();
	cout << "\nTask 1b:\n";
	task_1b();
	cout << "\nTask 1c:\n";
	task_1c();
	cout << "Done.\n";
	return 0;
}
