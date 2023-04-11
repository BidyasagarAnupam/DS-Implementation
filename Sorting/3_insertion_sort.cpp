#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int pivot = arr[i];
        int j = i - 1;
        while (arr[j] > pivot && j >= 0) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = pivot;
    }
}

int main() {
    int arr[] = {4, 6, 2, 7, 1};
    int size = 5;
    insertionSort(arr, size);
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    return 0;
}