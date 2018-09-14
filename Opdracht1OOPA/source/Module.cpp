#include "Module.h"

Module::Module(std::string name, Docent* teacher, int ec) : name(name), teacher(teacher), ec(ec) {
}

std::string Module::getName() {
	return name;
}

Docent* Module::getTeacher() {
	return teacher;
}

int Module::getEcs() {
	return ec;
}

//function that takes in a new amount of ecs to replace the old amount
void Module::setEcs(int ecs) {
	ec = ecs;
}

Module::~Module() {
	delete teacher, getTeacher();
}
