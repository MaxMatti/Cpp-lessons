#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <vector>
#include <math.h>

namespace testing {
	std::stringstream cout;
	std::stringstream cin;
	#include "../solutions/02-basic-maths.cpp"
};

// basic maths
void task_2a() {
	for (int i = 0; i < 100; ++i) {
		for (int j = 1; j < 100; ++j) {
			testing::cout.str("");
			testing::cout.clear();
			testing::task_2a(i, j);
			size_t current_pos = 0;
			std::vector<std::string> numbers = {std::to_string(i + j), std::to_string(i - j), std::to_string(i * j), std::to_string(i / j), std::to_string(i % j)};
			for (auto i : numbers) {
				current_pos = testing::cout.str().find(i, current_pos);
				if (current_pos == std::string::npos) {
					std::cout << "Unsuccessful.\nInput: (" << i << ", " << j << "), Output:\n\"" << testing::cout.str() << "\"\n";
					return;
				}
			}
		}
	}
	testing::cout.str("");
	testing::cout.clear();
	std::cout << "Successful.\n";
}

// faculty
void task_2b() {
	std::vector<int> numbers;
	numbers.push_back(1);
	for (int i = 1; i < 100; ++i) {
		numbers.push_back(numbers.back() * i);
	}
	for (size_t i = 0; i < numbers.size(); ++i) {
		if (numbers[i] != testing::task_2b(i)) {
			std::cout << "Unsuccessful.\nInput: " << i << ", Output: " << testing::task_2b(i) << "\n";
			return;
		}
	}
	std::cout << "Successful.\n";
}

// integer overflow
void task_2c() {
	for (short int i = 2; i < std::numeric_limits<short int>::max(); i += std::numeric_limits<short int>::max() / 100) {
		for (short int j = 2; j < std::numeric_limits<short int>::max(); j += std::numeric_limits<short int>::max() / 100) {
			short int tmp = i * j;
			if (testing::task_2c(i, j) != std::max(std::max(i, j), tmp)) {
				std::cout << "Unsuccessful.\nInput: (" << i << ", " << j << "), Output: " << testing::task_2c(i, j) << "\n";
				return;
			}
		}
	}
	std::cout << "Successful.\n";
}

// floating point precision
void task_2d() {
	for (int i = 1; i < 2048; i *= 2) {
		for (int j = 1; j < 2048; j *= 2) {
			for (int k = 1; j < 2048; j *= 2) {
				for (int l = 1; l < 2048; l *= 2) {
					float a = (float) i / j, b = (float) k / l;
					if (testing::task_2d(a, b) != (a * b / b == a)) {
						std::cout << "\nUnsuccessful.\nInput: (" << a << ", " << b << "), Output: " << testing::task_2d(a, b) << "\n";
						return;
					}
				}
			}
		}
	}
	std::cout << "\rSuccessful.\n";
}

// floating point positive infinity
void task_2e() {
	if (testing::task_2e() == std::numeric_limits<float>::infinity()) {
		std::cout << "Successful.\n";
	} else {
		std::cout << "Unsuccessful.\n";
	}
}

// floating point positive infinity
void task_2f() {
	if (testing::task_2f(true, true) != false) {
		std::cout << "Unsuccessful.\n";
		return;
	}
	if (testing::task_2f(true, false) != true) {
		std::cout << "Unsuccessful.\n";
		return;
	}
	if (testing::task_2f(false, true) != true) {
		std::cout << "Unsuccessful.\n";
		return;
	}
	if (testing::task_2f(false, false) != false) {
		std::cout << "Unsuccessful.\n";
		return;
	}
	std::cout << "Successful.\n";
}

int main() {
	std::cout << "\nTask 2a:\n";
	task_2a();
	std::cout << "\nTask 2b:\n";
	task_2b();
	std::cout << "\nTask 2c:\n";
	task_2c();
	std::cout << "\nTask 2d:\n";
	task_2d();
	std::cout << "\nTask 2e:\n";
	task_2e();
	std::cout << "\nTask 2f:\n";
	task_2f();
	std::cout << "\nDone.\n";
	return 0;
}
