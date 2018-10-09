#pragma once
#include "ClassDecorator.h"

class Farmer : public ClassDecorator {
public:
	Farmer(Class* c) : ClassDecorator(c) {
	}

	void render() {
		ClassDecorator::render();
		std::cout << "I'm a healthy farmer!" << std::endl;
	}
};
