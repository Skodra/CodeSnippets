#include <iostream>
#include <string>
#include "../String.hpp"
#include "../Entity.hpp"

// Ensures only temporary objecets can be accepted, 
// but reference itself is lvalue which would call still not call move operator
//String getString(String&& name)

String processString(String first)
{
	first[-1] = 'c';

	return first;
}

int main()
{
	String first = "Bojan";
	// If first gets moved to function argument, it will also be destroyed, if not move returned
	first = processString(std::move(first));

	// If there is move operation in String, we will not be able to avoid it.
	String second = processString(first);
	
	std::cout << "First, " << first << std::endl;
	std::cout << "Second, " << second << std::endl;
	std::cout << "-- -- -- --" << std::endl;
	std::cout << std::endl;

	// rvalues within constructor get deleted uppon its end
	Entity e1(std::move(first), 27);
	std::cout << "Outside 0, " << first << std::endl;
	std::cout << "Outside 1, " << e1 << std::endl;
	std::cout << "-- -- -- --" << first << std::endl;
	std::cout << std::endl;

	// Indirect constructor call for String
	//Entity e2(std::move(Entity("Drasko", 28)));
	Entity e2(std::move(e1));
	std::cout << "Outside 1, " << e1 << std::endl;
	std::cout << "Outside 2, " << e2 << std::endl;
	std::cout << "-- -- -- --" << first << std::endl;
	std::cout << std::endl;

	e1 = std::move(e1);
	std::cout << "Outside 1, " << e1 << std::endl;
	std::cout << "Outside 2, " << e2 << std::endl;
	std::cout << std::endl;

	return 0;
}
/*
String testString()
{
	String first = getString("Bojan");		// Initialized
	String second = getString("Drasko");	// Initialized
	first = second;							// Assigned reallocated
	second = first;							// Assigned reused
	// 1. If there is no rvalue assign operator
	//		Assigned reallocated - implicit conversion
	// 2. Otherwise
	//		Initialized - Implicit conversion to String
	//		Move - Already allocated resources transfered
	//		Deleted rvalue String
	first = "Mikelandjelo";
	if (0 == 1) // To intentionaly avoid NRVO
	{
		first = getString("Dragan");
	}
	else
	{
		first = getString("Bojan");
	}
	std::cout << "Outside 0, " << first << std::endl;
	std::cout << std::endl;

	return std::move(first);
}
*/