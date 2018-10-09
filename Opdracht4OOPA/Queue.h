#pragma once
#include <iostream>

namespace wes {
	template <typename T>
	class Queue {
	private:
		T* t;
		int len;
	public:
		Queue() {
			len = 0;
			t = new T[len];
		}

		void put(const T& element) {
			len++;
			T* _t = new T[len];
			for (int i = 0; i < len - 1; ++i) {
				_t[i] = t[i];
			}
			_t[len - 1] = element;
			delete[] t;
			t = new T[len];
			for (int i = 0; i < len; i++) {
				t[i] = _t[i];
			}
			delete[] _t;
		}

		void print() {
			for (int i = 0; i < len; i++) {
				std::cout << t[i];
				if (i < len - 1) {
					std::cout << ", ";
				}
			}
			std::cout << std::endl;
		}

		T get() {
			T _t = t[0];
			for (int i = 0; i < len; i++) {
				t[i - 1] = t[i];
			}
			len--;
			return _t;
		}

		int size() const {
			return len;
		}
	};
};