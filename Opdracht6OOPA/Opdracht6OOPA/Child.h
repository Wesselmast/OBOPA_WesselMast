#pragma once

#include <string>
#include <ostream>

class Child {
    public:
        Child(std::string name);
        Child(const Child& other);
    private:
        std::string name;
    public:
        friend std::ostream& operator<<(std::ostream& os, const Child& child);
};

