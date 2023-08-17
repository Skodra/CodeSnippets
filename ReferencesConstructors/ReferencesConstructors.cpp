#include <iostream>
#include <string>

class String 
{
public:
	// Default constructor
	String() = default;
	// Initializing constructor
	String(const char* const string)
	{
		size = strlen(string);
		setData(string);
		std::cout << "Created String " << data << "!" << std::endl;
	}
	// Copy constructor
	String(const String& other)
		:size(other.size)
	{
///>	memcpy(this, &other, sizeof(String)); // Default behavior
		setData(other.data);
		std::cout << "Copied String " << data << "!" << std::endl;
	}
	// Copy assigment operator
	void operator=(const String& other)
	{
		delete[] data;
		size = other.size;
		setData(other.data);
		std::cout << "Assigned String " << data << "!" << std::endl;
	}

	// Indexing operator, returning lvalue reference so it can be assigned to,
	// returning a reference to the terminating char if out of bounds
	char& operator[](unsigned int index)
	{
		if (index <= size)
		{
			return data[index];
		}
		return data[size];
	}
	friend std::ostream& operator<<(std::ostream& stream, const String& string);

	// Destructor
	~String()
	{
		std::cout << "Deleted String " << data << "!" << std::endl;
		delete[] data;
	}

private:
	char* data;
	unsigned int size;
	// Repeating code
	void setData(const char* const string)
	{
		data = new char[size + 1];
		memcpy(data, string, size);
		data[size] = '\0';
	}
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.data;
	return stream;
}

class Entity
{
public:
	// Default constructor
	// if member initializer list is not used, objects would be created with default constructor
	// and only then assined to.
	Entity()
//		:name("Unknown")
	{
		name = "Unknown";
		std::cout << "Created Entity " << name << "!" << std::endl;
	}
	// Initializing constructor
	Entity(const String& other)
		:name(other)
	{
///>	name = other; // Avoid assigment operator
		std::cout << "Copied Entity " << name << "!" << std::endl;
	}
	~Entity()
	{
		std::cout << "Deleted Entity" << name << "!" << std::endl;
	}
private:
	String name;
};

// Doesn't call destructor of returning object only if passed by value (copy)
// As we shoudn't with pointers, we shoudn't pass reference to an local stack variable upwards.
String stringFunc()
{
	String first = "Bojan";
	String second = first;
	second = first;

	second[2] = 'z';

	std::cout << first << second << std::endl;

	return second;
}

int main()
{
	String test = stringFunc();
	std::cout << "Outside, " << test << std::endl;

	// Implicit conversion of const char* to String inside constructor argument
	Entity entity("Drasko");

}