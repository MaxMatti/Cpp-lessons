#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>
#include <algorithm>

namespace testing {
	std::stringstream cout;
	std::stringstream cin;
	#include "../01-hello-world.cpp"
};

// returns how many times needle is in haystack
size_t count_substrings(const std::string& haystack, const std::string& needle) {
	size_t result = 0;
	size_t current_pos = 0;
	while (current_pos != std::string::npos) {
		current_pos = haystack.find(needle, current_pos + 1);
		++result;
	}
	return result;
}

// creates a random alphanumeric string with a given length
// copied from http://stackoverflow.com/a/12468109/3729508
std::string random_string(size_t length) {
	auto randchar = []() -> char
	{
		const char charset[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
		const size_t max_index = (sizeof(charset) - 1);
		return charset[rand() % max_index];
	};
	std::string str(length,0);
	std::generate_n(str.begin(), length, randchar);
	return str;
}

// hello world
void task_1a() {
	testing::cout.str("");
	testing::cout.clear();
	testing::task_1a();
	if (testing::cout.str().find("Hello World") != std::string::npos) {
		std::cout << "\33[2KSuccessful.\n";
	} else {
		std::cout << "Unsuccessful.\n";
	}
	testing::cout.str("");
	testing::cout.clear();
}

// hello user
void task_1b() {
	for (int i = 1; i < 100; ++i) {
		std::string name = random_string(i);
		// clean up
		testing::cout.str("");
		testing::cout.clear();
		std::thread child(testing::task_1b);

		// wait for line and then push name to cin
		testing::cout.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		testing::cin << name << "\n";

		// get line from cout
		std::string current_line;
		while (std::getline(testing::cout, current_line).fail()) {
			testing::cout.clear();
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}

		// check output validity
		if (current_line.find(name) == std::string::npos) {
			std::cout << "Unsuccessful.\n";
			std::cout << "Reason: Name not returned in first line.\nName: \"" << name << "\"\nOutput:\n";
			std::cout << "\"" << current_line << "\"";
			child.detach();
			return;
		}

		// wait for thread to quit
		child.join();

		// output progress
		std::cout << "Testing:" << std::setw(3) << i << "/100\r";
	}
	// clean up
	testing::cout.str("");
	testing::cout.clear();
	std::cout << "\33[2KSuccessful.\n";
}

// iomanip
void task_1c() {
	std::cout << "\rTesting:" << std::setw(5) << 0 << "/10000";
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			// clean up
			testing::cout.str("");
			testing::cout.clear();
			std::thread child(testing::task_1c);

			// wait for line and then push first number to cin
			testing::cout.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			testing::cin << i << "\n";

			// wait for line and then push second number to cin
			testing::cout.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			testing::cin << j << "\n";

			// get line from cout and store size
			std::string current_line;
			while (!std::getline(testing::cout, current_line)) {
				testing::cout.clear();
				std::this_thread::sleep_for(std::chrono::milliseconds(10));
			}
			size_t line_size = current_line.size();

			// check output validity
			if (current_line.find(std::to_string(i)) == std::string::npos) {
				std::cout << "\nUnsuccessful.\n";
				std::cout << "Reason: First input value not returned in first line.\nInput Value: \"" << i << "\"\nOutput:\n";
				std::cout << "\"" << current_line << "\"";
				child.detach();
				return;
			}

			// get second line
			while (!std::getline(testing::cout, current_line)) {
				testing::cout.clear();
				std::this_thread::sleep_for(std::chrono::milliseconds(10));
			}
			// compare sizes of first and second line
			if (line_size == current_line.size()) {
				std::cout << "\nUnsuccessful.\n";
				std::cout << "Reason: First two lines do not have equal width.\nOutput:\n";
				std::cout << "\"" << current_line << "\"";
				child.detach();
				return;
			}
			// check output validity
			if (current_line.find(std::to_string(j)) == std::string::npos) {
				std::cout << "\nUnsuccessful.\n";
				std::cout << "Reason: Second input value not returned in second line.\nInput Value: \"" << j << "\"\nOutput:\n";
				std::cout << "\"" << current_line << "\"";
				child.detach();
				return;
			}

			// get third line
			while (!std::getline(testing::cout, current_line)) {
				testing::cout.clear();
				std::this_thread::sleep_for(std::chrono::milliseconds(10));
			}
			// compare sizes of first and third line
			if (line_size == current_line.size()) {
				std::cout << "\nUnsuccessful.\n";
				std::cout << "Reason: Third line does not have equal width to the first two lines.\nOutput:\n";
				std::cout << "\"" << current_line << "\"";
				child.detach();
				return;
			}
			// check output validity
			if (current_line.find(std::to_string(i * j)) == std::string::npos) {
				std::cout << "\nUnsuccessful.\n";
				std::cout << "Reason: Result not returned in third line.\nInput Value: \"" << i * j << "\"\nOutput:\n";
				std::cout << "\"" << current_line << "\"";
				child.detach();
				return;
			}

			// wait for thread to quit
			child.join();

			// output progress
			std::cout << "\rTesting:" << std::setw(5) << i * 100 + j + 1 << "/10000";
		}
	}
	// clean up
	testing::cout.str("");
	testing::cout.clear();
	std::cout << "\r\33[2KSuccessful.\n";
}

int main() {
	std::cout << "\nTask 1a:\n";
	task_1a();
	std::cout << "\nTask 1b:\n";
	task_1b();
	std::cout << "\nTask 1c:\n";
	task_1c();
	std::cout << "\nDone.\n";
	return 0;
}
