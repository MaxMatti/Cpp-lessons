#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	cout << "Please enter the height and width:\n";
	int height, width;
	cin >> height >> width;
	cout << "Height: " << setw(4) << height << "\n";
	cout << "Width:  " << setw(4) << width << "\n";
	cout << "Area:   " << setw(4)
		 << height * width << "\n";
	return 0;
}
