#include "Student.h"



Student::Student()
{
	std::vector<std::string>names = {
		"Bob Jeltes",
		"Pepijn Kok",
		"Chris Conquet",
		"Daan de Bruijn",
		"Jelle Booij",
		"Jeremy Koskamp",
		"Kevin Absen",
		"Mick Teunissen",
		"Mick Gerritsen",
		"Niels Vriezen"
	};
	name = names[rand() % names.size()];
}

std::string Student::getName() {
	return name;
}

std::vector<Module*> Student::getModules() {
	return assignedModules;
}

int Student::getEcs() {
	int ecs = 0;
	//loop through all the assigned modules
	for (auto mod : assignedModules) {
		//get the combine the ecs from those modules
		ecs += mod->getEcs();
	}
	return ecs;
}

//function that adds chosen modules to the assigned modules
void Student::assignModule(Module* module) {
	assignedModules.push_back(module);
}

//function that deletes modules at a specified index
void Student::leaveModule(int index) {
	//if the index is within the size of the array
	if (index < assignedModules.size()) {
		//delete the module at that index
		assignedModules.erase(assignedModules.begin() + index);
	}
}

Student::~Student()
{
}
