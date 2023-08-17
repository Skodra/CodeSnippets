#include <iostream>
#include <vector>
#include <algorithm>

void my_sort(std::vector<int> my_vector)
{
    std::ranges::sort(my_vector);
}
void my_print(std::vector<int>& my_vector) {
    std::cout << "My vector: ";
    for (auto value : my_vector) {
        std::cout << value << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> my_vector;
    my_vector.reserve(10);
    for (int i = 12; i > 0; i--) {
        my_vector.push_back(i);
        std::cout << "Size: " << my_vector.size() << '\n';
        std::cout << "Capacity: " << my_vector.capacity() << '\n';
    }

    my_print(my_vector);
    my_sort(my_vector); ///> No effect
    my_print(my_vector);
    my_sort(std::move(my_vector)); ///> Transfered to funciton
    my_print(my_vector);
}