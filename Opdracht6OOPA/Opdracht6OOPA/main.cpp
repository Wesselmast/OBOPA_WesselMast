#include <iostream>
#include "Parent.h"

int main() {

    std::shared_ptr<Parent> p1 = std::make_shared<Parent>("Parent1");
    std::cout << "P1:" << *p1 << std::endl;

    std::shared_ptr<Parent> p2 = p1; //geen copy-constructor meer
    std::cout << "P2:" << *p2 << std::endl;

    std::shared_ptr<Parent> p3 = std::make_shared<Parent>("Parent3");
    std::cout << "P3:" << *p3 << std::endl;

    p3 = p1; //geen assignment operator meer
    std::cout << "P3:" << *p3 << std::endl;
	std::cout << "Reference count: " << p1.use_count() << std::endl;


	std::cin.get();
    return 0;
}