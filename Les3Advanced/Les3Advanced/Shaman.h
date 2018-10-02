#pragma once
#include "ClassDecorator.h"

class Shaman : public ClassDecorator {
public:
	Shaman(Class* c) : ClassDecorator(c) {
	}

	void render() {
		ClassDecorator::render();
		std::cout << "I'm a fearsome shaman!" << std::endl;
	}
};

