#pragma once
#include <string>
#include <vector>
#include "Module.h"

class Student
{
private:
	std::string name;
	std::vector<Module*> assignedModules;
	int ecs;
public:
	Student();
	std::string getName();
	std::vector<Module*> getModules();
	void assignModule(Module* module);
	void leaveModule(int index);
	int getEcs();
	~Student();
};

