#include <iostream>
#include <string>
using namespace std;

int main() {
	int amount = 5;
	string text = "test";

	cout << "\nWhile:\n";
	while (amount < 8) {
	    cout << text << "\n";
	    ++amount;
	}

	cout << "\nFor:\n";
	for (int i = 4; i < amount; ++i) {
	    cout << text << "\n";
	}

	cout << "\nRanged for:\n";
	for (auto i : text) {
	    cout << i << "\n";
	}
	return 0;
}
