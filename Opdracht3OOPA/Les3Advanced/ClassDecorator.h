#pragma once
#include "Class.h"

class ClassDecorator : public Class {
protected:
	Class* curClass;
public:
	ClassDecorator(Class* c) {
		curClass = c;
	}
	virtual void render() {
		curClass->render();
	}
};

