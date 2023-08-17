#include <iostream>
#include <cstdlib> // For std::swap

class sortingStrategy
{
public:
    virtual void sort(int arr[], int size) = 0;
};

class quickSorting : public sortingStrategy
{
public:
    void sort(int arr[], int size)
    {
        quickSort(arr, 0, size - 1);
    }
private:
    void quickSort(int arr[], int low, int high) {
        if (low >= high)
            return;

        int pi = partition(arr, low, high);

        // Separately sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }

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
};

class mergeSorting : public sortingStrategy
{
public:
    void sort(int arr[], int size)
    {
        mergeSort(arr, 0, size - 1);
    }
private:
    void mergeSort(int arr[], int l, int r) {
        if (l >= r)
            return; // Base case

        // Find middle point of array
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }

    // Data duplication only on merge, pass by pointer
    void merge(int arr[], int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;

        // Create temp arrays using dynamic allocation
        int* L = new int[n1];
        int* R = new int[n2];

        // Copy data to temp arrays L[] and R[]
        for (int i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[m + 1 + j];

        // Merge the temp arrays back into arr[l..r]
        int i = 0;
        int j = 0;
        int k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        // Copy the remaining elements of L[], if any
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        // Copy the remaining elements of R[], if any
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }

        // Clean up the dynamically allocated memory
        delete[] L;
        delete[] R;
    }
};

class data
{
public:
    data(int size, sortingStrategy* strategy)
        : size(size), arr(new int[size]), strategy(strategy)
    {
        for (int i = 0; i < size; i++)
            arr[size - 1 - i] = i + 1;
    }

    void sort()
    {
        strategy->sort(arr, size);
    }

    void print()
    {
        for (int i = 0; i < size; i++)
            std::cout << arr[i] << ", ";
        std::cout << std::endl;
    }

private:
    int size;
    int* arr;
    sortingStrategy* strategy;
};


int main()
{
    quickSorting strategy1;
    quickSorting strategy2;
    data toBeSorted{10, &strategy2};

    std::cout << "Unsorted array: ";
    toBeSorted.print();

    toBeSorted.sort();
    std::cout << "Sorted array: ";
    toBeSorted.print();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
