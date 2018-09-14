#include <iostream>
#include <vector>
#include <ctime>
#include "Docent.h"
#include "Student.h"
#include "Module.h"

//macro for readability
#define GETRANDOMEC rand() % ((5 - 2) + 1) + 2
int main() {
	srand((int)time(NULL));
	std::vector<Student*> studenten;
	std::vector<Docent*> docenten;
	std::vector<Module*> modules;

	docenten.push_back(new Docent("Edwin van Ouwerkerk"));
	docenten.push_back(new Docent("Aaron Oostdijk"));
	docenten.push_back(new Docent("Richard van Tol"));

	//assign teachers to modules with a random EC
	modules.push_back(new Module("Object-Oriented Programming", docenten[0], GETRANDOMEC));
	modules.push_back(new Module("Kernmodule GDV2", docenten[1], GETRANDOMEC));
	modules.push_back(new Module("Audio Games and Interacion", docenten[2], GETRANDOMEC));

	//loop prints each modules' given properties
	for (auto mod : modules) {
		std::cout << mod->getName() << " is taught by " << mod->getTeacher()->getName() << " for " << mod->getEcs() << " EC\n";
	}
	std::cout << "\n";

	for (size_t i = 0; i < 10; i++) {
		studenten.push_back(new Student());
	}

	for (auto stu : studenten) {
		//alias for the modules vector to allow removing elements
		std::vector<Module*> _modules = modules;
		//loop through a random amount of times
		for (size_t i = 0; i < 1 + (rand() % modules.size()); i++) {
			//get the index of a random module, assign it to the student and then erase it from the list
			int index = rand() % _modules.size();
			stu->assignModule(_modules[index]);
			_modules.erase(_modules.begin() + index);
		}
		std::cout << stu->getName() << " follows ";
		for (auto i : stu->getModules()) {
			std::cout << i->getName();
			//"and " prints every time because the amount of ECs follows
			std::cout << " and ";
		}
		//get the amount of ECs
		std::cout << "has " << stu->getEcs() << "ECs\n";
	}
	std::cout << "\n";
	//get a random module
	int rMod = rand() % modules.size();
	//change it's ECs
	modules[rMod]->setEcs(GETRANDOMEC);
	std::cout << modules[rMod]->getName() << " now gives " << modules[rMod]->getEcs() << "ECs\n\n";
	for (auto stu : studenten) {
		std::cout << stu->getName() << " now has " << stu->getEcs() << "ECs\n";
	}
	std::cout << "\n";
	//get a random student
	int rStud = rand() % studenten.size();
	//get another random module
	rMod = rand() % modules.size();
	//student leaves the chosen module
	studenten[rStud]->leaveModule(rMod);
	std::cout << studenten[rStud]->getName() << " left " << modules[rMod]->getName() << "!\n\n";
	for (auto stu : studenten) {
		std::cout << stu->getName() << " now has " << stu->getEcs() << "ECs\n";
	}
	docenten.clear();
	studenten.clear();
	modules.clear();
	std::cin.get();
	return 0;
}