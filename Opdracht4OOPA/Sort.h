#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

namespace wes {
	template <typename T, int size> 
	class Sort {
	private:
		void swap(T& a, T& b) {
			T t = a;
			a = b;
			b = t;
		}
	public:
		void sort(T (&arr)[size]) {
			for (int i = 1; i < size; i++) {
				if (arr[i] > arr[i - 1]) {
					swap(arr[i], arr[i - 1]);
					sort(arr);
				}
			}
		}
		void print(T (&arr)[size]) {
			for (int i = 0; i < size; i++) {
				std::cout << arr[i]; 
				if (i < size - 1) {
					std::cout << ", ";
				}
			}
			std::cout << std::endl;
		}
	};
};
