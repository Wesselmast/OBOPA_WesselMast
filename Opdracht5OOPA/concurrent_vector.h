#pragma once
#include <iostream>
#include <future>
#include <vector>

std::mutex mt;

namespace wes {
	template<typename T>
	class concurrent_vector {
	private:
		std::vector<T> vec;
		std::mutex mt;
	public:
		void push_back(T t) {
			std::unique_lock<std::mutex> lock(mt);
			vec.push_back(t);
		}

		void print() {
			for (auto& v : vec) {
				std::cout << v << std::endl;
			}
		}
	};
}
