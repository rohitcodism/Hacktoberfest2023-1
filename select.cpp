// selection sort

#include <iostream>
#include <vector>

// Function to perform selection sort on an array
void selectionSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in the unsorted part of the array
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        std::swap(arr[i], arr[minIndex]);
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

    selectionSort(arr);

    std::cout << "Sorted array (ascending order):";
    for (int num : arr) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    return 0;
}
