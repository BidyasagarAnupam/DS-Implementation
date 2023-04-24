#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e) {
    int pivot = arr[s];

    int cnt = 0;
    for(int i=s+1; i<=e; i++) {
        if(arr[i] <= pivot ) cnt++;
    }
    int pivotIndex = s+cnt;
    swap(arr[s], arr[pivotIndex]);

    int i=s, j=e;
    while(i < pivotIndex && j > pivotIndex) {
        while(arr[i] < arr[pivotIndex]) {
            i++;
        } 
        while(arr[j] > arr[pivotIndex]) {
            j--;
        }
        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e) {
    if(s>=e) return;
    int p = partition(arr, s, e);
    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
}

int main() {
    int arr[9] = {5, 2, 3, 4, 1, 1, 8, 0, 15};
    int n = 9;
    quickSort(arr, 0, n-1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}