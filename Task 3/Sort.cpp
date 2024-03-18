#include <iostream>
#include <algorithm>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int partIndex = partition(arr, low, high); 
        quickSort(arr, low, partIndex - 1); 
        quickSort(arr, partIndex + 1, high); 
    }
}

