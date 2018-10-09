#pragma once
#include "ClassDecorator.h"

class Soldier : public ClassDecorator {
public:
	Soldier(Class* c) : ClassDecorator(c) {
	}

	void render() {
		ClassDecorator::render();
		std::cout << "I'm a brave soldier!" << std::endl;
	}
};
