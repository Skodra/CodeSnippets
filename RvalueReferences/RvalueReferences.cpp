#include <iostream>

// Using const lref as it can accept all references
void printRef(const int& ref)
{
	std::cout << "ref(" << &ref << ") = " << ref << std::endl;
}

// Same with or without const
const int getRValue()
{
	static int a = 0;
	a += 10;

	return a;
///%return 50; // Same
}

///> Needs to return a variable, rvalue can't be reutrned
int& getRef()
{
	static int a = 0;
	a += 10;

	return a;
}

///>Unsafe return - Same as returning a pointer to a variable allocated locally in a funciton
const int& getRef2()
{
	int a = 10;

	return a;
///%return 50; // Can be, the special temp rule will apply
}


int main()
{
	int a = getRValue();
	const int b = getRValue();

	// LValue reference can only refer lvalue
	int& lref_a = a; lref_a++;
///>int& lref_b = b;           // Incorrect
///>int& lref_c = getRValue(); // Incorrect
///>int& lref_d = getRValue(); // Incorrect
///>int& lref_d = getValue2(); // Incorrect


		// Const LValue can refer everything
	const int& clref_a = a;
	const int& clref_b = b;
	const int& clref_c = getRValue(); ///! Special rule - Compiler creates location with "int temo = 31" and returns a reference to it

	// RValue reference can only refer rvalue
///>int&& rref_a = a; // Incorrect
///>int&& rref_b = b; // Incorrect
	int&& rref_c = getRValue(); rref_c++; ///! If reference is not-const, reference becomes modifiable, as it works the same as rvalue reference assigment to "const int&".
	const int&& rref_d = getRValue();
///>rref_d++; // Incorrect

	// Geting a reference, only works with lvalue references
	int& ref_a = getRef(); ref_a++; ///> Unsafe return
	const int& ref_b = getRef2();	///> Const needs to be keept on left side


	// Printing
	printRef(lref_a);

	printRef(clref_a);
	printRef(clref_b);
	printRef(clref_c);

	printRef(rref_c);
	printRef(rref_d);

	printRef(ref_a);
	printRef(ref_b);

}