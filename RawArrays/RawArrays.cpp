#include <iostream>

void fa(int x[], int d) {
	for(int i = 0; i < d; i++) {
		std::cout << x[i] << ", ";
	}
	std::cout << std::endl;
}


int main() {
	int x = 1;
	int a[5] = { 0, 1, 2 , 3, 4 };
	int a2[3][5] = {
		{ 7, 8, 9 , 3, 4 },
		{ 7, 8, 9 , 3, 4 },
		{ 7, 8, 9 , 3, 4 }
	};
	int a3[2][3][4] = {
		{{5, 4, 3, 2}, {5, 4, 3, 2}, {5, 4, 3, 2}},
		{{5, 4, 3, 2}, {5, 4, 3, 2}, {5, 4, 3, 2}}
	};

	int* y = new int;
	int* b = new int[5];
	int** b2 = new int* [10];

	fa(a, 5);

	return 0;
}