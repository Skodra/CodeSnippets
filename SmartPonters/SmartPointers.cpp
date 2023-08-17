#include <iostream>
#include "String.hpp"

class MyClass {
public:
    MyClass() {
        std::cout << "Constructor called." << std::endl;
    }

    MyClass(const MyClass &t) {
        std::cout << "Copy constructor called." << std::endl;
    }

    MyClass(MyClass &&t) {
        std::cout << "Move constructor called." << std::endl;
    }

    ~MyClass() {
        std::cout << "Destructor called." << std::endl;
    }
};

MyClass createObject() {
    std::cout << "Function start." << std::endl;

    MyClass obj;

    std::cout << "Function end." << std::endl;

    return obj;
}

int main() {
    MyClass returnedObject = createObject();

    std::cout << "End of main." << std::endl;

    return 0;
}
