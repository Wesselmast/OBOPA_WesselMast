#pragma once
#include <iostream>
#include <string>

class Class {
public:
	std::string name;
	virtual void render() {
		std::cout << name << std::endl;
	}
};