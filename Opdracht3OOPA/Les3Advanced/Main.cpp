#include "Class.h"
#include "Orc.h"
#include "Elf.h"
#include "Farmer.h"
#include "Shaman.h"
#include "Soldier.h"
#include <vector>

int main() {
	std::vector<Class*> cList;

	cList.push_back(new Farmer(new Orc()));
	cList.push_back(new Shaman(new Orc()));
	cList.push_back(new Soldier(new Orc()));
	cList.push_back(new Farmer(new Elf()));
	cList.push_back(new Shaman(new Elf()));
	cList.push_back(new Soldier(new Elf()));

	for (int i = 0; i < cList.size(); i++) {
		cList[i]->render();
		if (i == (cList.size() / 2) - 1) {
			std::cout << std::endl;
		}
	}

	for (auto& c : cList) {
		delete c;
	}

	std::cin.get();
	return 0;
}