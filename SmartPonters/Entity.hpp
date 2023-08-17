#pragma once
#include <iostream>
#include "String.hpp"

class Entity
{
public:
	// Default constructor
	Entity();

	// Initializing constructor
	Entity(const String& other, unsigned short age);

	// Copy constructor
	Entity(const Entity& other);

	// Move initiliazer
	Entity(String&& name, unsigned short age) noexcept;

	// Move constructor
	Entity(Entity&& other) noexcept;

	// Move assignment opertator
	void operator=(Entity&& other) noexcept;

	friend std::ostream& operator<<(std::ostream& stream, const Entity& other);

	~Entity();
private:
	String name;
	unsigned short age;
};