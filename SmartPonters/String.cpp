#include "String.hpp"

unsigned int String::count = 0;

// Default constructor
String::String()
	:size(0), data(nullptr)
{
	count++;
	instance = count;
	std::cout << "Default String " << *this << std::endl;
}
// Initializing constructor
String::String(const char* const string)
{
	size = strlen(string);
	setData(string);
	count++;
	instance = count;
	std::cout << "Initialized String " << *this << std::endl;
}
// Copy constructor
String::String(const String& other)
	:size(other.size)
{
///>memcpy(this, &other, sizeof(String)); // Default behavior
	setData(other.data);
	count++;
	instance = count;
	std::cout << "Copied String " << *this << std::endl;
}
// Copy assigment operator
void String::operator=(const String& other)
{
	// Decide whether to reallocate
	if (size < other.size)
	{
		delete[] data;
		size = other.size;
		setData(other.data);
		std::cout << "Assigned reallocated String " << *this << std::endl;
	}
	else
	{
		size = other.size;
		memcpy(data, other.data, other.size);
		std::cout << "Assigned reused String " << *this << std::endl;
	}
}


// Move constructor
String::String(String&& other) noexcept
	:size(other.size), data(other.data)
{
	// Set zero state for old object
	other.size = 0;
	other.data = nullptr;
	count++;
	instance = count;
	std::cout << "Moved String " << *this << std::endl;
}
// Move assignment opertator
void String::operator=(String&& other) noexcept
{
	// Check if both operands are not pointing to the same data
	if (data != other.data)
	{
		delete[] data;
		size = other.size;
		data = other.data;
		instance = other.instance;
	}
	// Don't loose the pointer
	if (this != &other)
	{
		other.size = 0;
		other.data = nullptr;
	}
	std::cout << "Moved String " << *this << std::endl;
}

// Indexing operator, returning lvalue reference so it can be assigned to,
// returning a reference to the terminating char if out of bounds
char& String::operator[](int index)
{
	if (index < 0)
		index = getSize() - 1;

	if (index <= size)
		return data[index];
	else
		return data[size];
}
std::ostream& operator<<(std::ostream& stream, const String& string)
{
	if (string.size > 0)
	{
		stream << string.data << "(" << string.instance << ")";
	}
	return stream;
}

unsigned short String::getSize() const
{
	return size;
}

// Destructor
String::~String()
{
	std::cout << "Deleted String " << *this << std::endl;
	delete[] data;
}
// Repeating code
void String::setData(const char* const string)
{
	data = new char[size + 1];
	memcpy(data, string, size);
	data[size] = '\0';
}