#pragma once
#include <iostream>

class String
{
public:
	// Default constructor
	String();
	// Initializing constructor
	String(const char* const string);
	// Copy constructor
	String(const String& other);
	// Copy assigment operator
	void operator=(const String& other);
	// Move constructor
	String(String&& other) noexcept;
	// Move assignment opertator
	void operator=(String&& other) noexcept;

	// Indexing operator, returning lvalue reference so it can be assigned to,
	// returning a reference to the terminating char if out of bounds
	char& operator[](int index);
	friend std::ostream& operator<<(std::ostream& stream, const String& string);

	unsigned short getSize() const;
	// Destructor
	~String();

private:
	char* data;
	unsigned int size;
	static unsigned int count;
	unsigned int instance;
	// Repeating code
	void setData(const char* const string);
};

std::ostream& operator<<(std::ostream& stream, const String& string);