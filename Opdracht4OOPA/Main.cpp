#include "Sort.h"
#include "Queue.h"
#include <algorithm>

template<typename T>
void print(std::vector<T> v) {
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i];
		if (i < v.size() - 1) {
			std::cout << ", ";
		}
	}
	std::cout << std::endl;
}

int main() {

	std::cout << "String sorting assignment:" << std::endl;
#pragma region string sort
	std::string stringArr[] = {
		"Object", "Oriented", "Programming", "Advanced"
	};
	const int stringSize = sizeof(stringArr) / sizeof(stringArr[0]);
	wes::Sort<std::string, stringSize> s;
	s.sort(stringArr);
	s.print(stringArr);
#pragma endregion
	std::cout << "\nFloat sorting assignment:" << std::endl;
#pragma region float sort
	float floatArr[] = {
	1.0f, 3.5f, 3.2f, 4.634f, 2.0f, 1.123456f, 2.8f, 5.9f, 8.0f, 10.523f
	};
	const int floatSize = sizeof(floatArr) / sizeof(floatArr[0]);
	wes::Sort<float, floatSize> i;
	i.sort(floatArr);
	i.print(floatArr);
#pragma endregion
	std::cout << "\nQueue assignment:" << std::endl;
#pragma region queue
	wes::Queue<int> q;
	const int qSize = 10;
	for (int i = 0; i < qSize; i++) {
		q.put(rand() % 99);
	}
	for (int i = 0; i < qSize / 2; i++) {
		q.get();
	}
	q.print();
#pragma endregion

	std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };

	std::cout << "\nColour sort assignment:" << std::endl;
#pragma region colour sort
	std::vector<std::string> v1;
	std::vector<std::string> v2;
	std::sort(colours.begin(), colours.end());
	for (auto& c : colours) {
		if (c < "purple") {
			v1.emplace_back(c);
		}
		else {
			v2.emplace_back(c);
		}
	}
	std::cout << "- First half: ";
	print(v1);
	std::cout << "- Second half: ";
	print(v2);
#pragma endregion
	std::cout << "\nUppercase assignment:" << std::endl;
#pragma region uppercase
	for (int i = 0; i < colours.size(); i++) {
		for (int j = 0; j < colours[i].length(); j++) {
			colours[i][j] = toupper(colours[i][j]);
		}
	}
	print(colours);
#pragma endregion
	std::cout << "\nRemove duplicates assignment:" << std::endl;
#pragma region remove duplicates
	std::unique(colours.begin(), colours.end());
	colours.resize(7);
	print(colours);
#pragma endregion

	std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };

	std::cout << "\nRemove negative elements assignment:" << std::endl;
#pragma region remove negative elements
	std::vector<double> _numbers1;
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] >= 0) {
			_numbers1.emplace_back(numbers[i]);
		}
	}
	print(_numbers1);
#pragma endregion
	std::cout << "\nEven or Odd assignment:" << std::endl;
#pragma region even or odd?
	for (auto& n : numbers) {
		if (((int)n) % 2 == 0) {
			std::cout << "Even, ";
		}
		else {
			std::cout << "Odd, ";
		}
	}
	std::cout << std::endl;
#pragma endregion
	std::cout << "\nMath assignment:" << std::endl;
#pragma region bunch of math
	double sum = 0;
	double product = 1.0;
	for (int i = 0; i < numbers.size(); i++) {
		sum += numbers[i];
		product *= numbers[i];
	}
	double average = sum / 2;
	std::cout << "Sum: " << sum << std::endl;
	std::cout << "Average: " << average << std::endl;
	std::cout << "Product: " << product << std::endl;

#pragma endregion

	std::cin.get();
	return 0;
}