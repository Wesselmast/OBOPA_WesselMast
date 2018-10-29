#pragma once
#include "concurrent_vector.h"

wes::concurrent_vector<int> cv;

void addToVec(int amt) {
	for (int i = 1; i < amt + 1; i++) {
		cv.push_back(i);
	}
}

void subtractFromVec(int amt) {
	for (int i = -1; i > -amt - 1; i--) {
		cv.push_back(i);
	}
}

struct Opdracht1 {
	Opdracht1() {
		std::thread t1(addToVec, 100);
		std::thread t2(subtractFromVec, 50);
		t1.join();
		t2.join();
		cv.print();
	}
};