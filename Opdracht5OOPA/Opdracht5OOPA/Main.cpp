#include "concurrent_vector.h"
#include <queue>

#pragma region Opdracht1
auto* cv = new wes::concurrent_vector<int>();

void addToVec(int amt) {
	for (int i = 1; i < amt + 1; ++i) {
		std::async(&wes::concurrent_vector<int>::push_back, cv, i);
	}
}

void subtractFromVec(int amt) {
	for (int i = -1; i > -amt - 1; --i) {
		std::async(&wes::concurrent_vector<int>::push_back, cv, i);
	}
}
#pragma endregion

#pragma region Opdracht2
int c = 0;
bool done = false;
std::queue<int> goods;

std::mutex mt1, mt2;
std::condition_variable cond1, cond2;

void producer() {
	std::unique_lock<std::mutex> lock(mt2);
	for (int i = 0; i < 500; ++i) {
		{
			std::unique_lock<std::mutex> locker(mt1);
			goods.push(i);
			c++;
		}
		cond1.notify_one();
		cond2.wait(lock);
	}
	done = true;
	cond1.notify_one();
}

void consumer() {
	std::unique_lock<std::mutex> lock(mt1);
	while (!done) {
		cond1.wait(lock);
		while (!goods.empty()) {
			std::lock_guard<std::mutex> locker(mt2);
			goods.pop();
			c--;
		}
		cond2.notify_one();	
	}
}
#pragma endregion

int main() {
	int amtToRun = 250;

	//Opdracht 1
	{
		addToVec(amtToRun);
		subtractFromVec(amtToRun);
		cv->print();
		delete cv;
	}
	//Opdracht 2
	{
		for (int i = 0; i < amtToRun; i++) {
			done = false;
			std::thread cons(consumer);
			std::thread prod(producer);
			cons.detach();
			prod.join();
			std::cout << "Net: " << c << std::endl;
		}
	}

	std::cin.get();
	return 0;
};