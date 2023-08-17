#include <iostream>
#include <array>
#include <algorithm>

int main()
{
    std::array<int, 5> arr = { 14, 211, 31, 422, 5 };

    std::cout << "Array: ";
    for (auto it = arr.begin(); it < arr.end(); it += 1)
    {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;

    std::cout << "Array in reverse: ";
    for (auto it = arr.rbegin(); it < arr.rend(); it++)
    {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;

    std::cout << "Sorted array: ";
    //std::sort(arr.begin(), arr.end());
    std::ranges::sort(arr);
    for (auto value : arr)
    {
        std::cout << value << ", ";
    }
    std::cout << std::endl;
}
