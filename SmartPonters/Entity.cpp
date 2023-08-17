#include "Entity.hpp"

// Default constructor
// if member initializer list is not used, objects would be created with default constructor
// and only then assined to.
Entity::Entity()
	:name("Unknown"), age(0)
{
	std::cout << "Created Entity " << *this << "!" << std::endl;
}

// Initializing constructor
Entity::Entity(const String& name, unsigned short age)
	:name(name), age(age)
{
	std::cout << "Initialized Entity " << *this << "!" << std::endl;
}

// Copy constructor
Entity::Entity(const Entity& other)
	:name(other.name), age(other.age)
{
	std::cout << "Copied Entity " << *this << "!" << std::endl;
}

// Move initiliazer
Entity::Entity(String&& name, unsigned short age) noexcept
	:name(std::move(name)), age(age)
{
	std::cout << "Moved(arguments) Entity " << *this << "!" << std::endl;
}

// Move constructor
Entity::Entity(Entity&& other) noexcept
	:name(std::move(other.name)), age(other.age)
{
	std::cout << "Moved Entity " << *this << "!" << std::endl;
}

// Move assignment opertator
void Entity::operator=(Entity&& other) noexcept
{
	name = std::move(other.name);
	age = other.age;
	std::cout << "Moved(assignment) Entity " << *this << "!" << std::endl;
}

Entity::~Entity()
{
	std::cout << "Deleted Entity " << *this << "!" << std::endl;
}

std::ostream& operator<<(std::ostream& stream, const Entity& other)
{
	if (other.name.getSize() > 0)
	{
		stream << other.name << "(" << other.age << ")";
	}
	return stream;
}