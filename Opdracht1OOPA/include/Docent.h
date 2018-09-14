#pragma once
#include <string>
#include <vector>

class Docent
{
private:
	std::string name;
public:
	Docent(std::string name);
	std::string getName();
	~Docent();
};

