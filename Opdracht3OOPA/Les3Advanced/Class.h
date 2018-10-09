#pragma once
#include <iostream>
#include <string>

class Class {
protected:
	std::string name;
public:
	virtual void render() = 0;
};