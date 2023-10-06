// quick sort
#include <iostream>
#include <vector>

// Function to partition the array and return the pivot index
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Choose the last element as the pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;
            // Swap arr[i] and arr[j]
            std::swap(arr[i], arr[j]);
        }
    }

    // Swap arr[i + 1] and arr[high] (the pivot)
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Function to perform quick sort
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // Find pivot element such that
        // element smaller than pivot are on the left
        // and elements greater than pivot are on the right
        int pivotIndex = partition(arr, low, high);

        // Recursively sort elements before and after pivot
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int n = arr.size();

    std::cout << "Original array:";
    for (int num : arr) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    quickSort(arr, 0, n - 1);

    std::cout << "Sorted array:";
    for (int num : arr) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    return 0;
}
