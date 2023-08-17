#include <iostream>
#include <cstdlib> // For std::swap

// Partition the array using the last element as the pivot
int partition(int arr[], int low, int high) {
    int pi = low; // Index of the last element smaller than pivot

    for (int i = low; i < high; i++) {
        if (arr[i] <= arr[high]) {
            std::swap(arr[pi], arr[i]);
            pi++;
        }
    }
    std::swap(arr[pi], arr[high]);
    return pi;
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low >= high)
        return;

    int pi = partition(arr, low, high);

    // Separately sort elements before and after partition
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
}

int main() {
    int arr[] = { 10, 2, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Given array is \n";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    quickSort(arr, 0, n - 1);

    std::cout << "Sorted array is \n";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
