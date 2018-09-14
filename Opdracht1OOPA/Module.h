#pragma once
#include "Docent.h"
#include <string>
#include <vector>

class Module
{
private:
	std::string name;
	std::vector<std::string> names;
	Docent* teacher;
	int ec;
public:
	Module(std::string name, Docent* teacher, int ec);
	std::string getName();
	Docent* getTeacher();
	int getEcs();
	void setEcs(int ecs);
	~Module();
};

