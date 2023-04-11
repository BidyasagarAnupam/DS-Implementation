#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int s1, int e1, int s2, int e2) {
    int size = (e1 - s1) + (e2 - s2);
    int temp[size];
    int i = s1, j = s2, k = 0;
    while (i <= e1 && j <= e2) {
        if (a[i] < a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }
    while (i <= e1) {
        temp[k++] = a[i++];
    }
    while (j <= e2) {
        temp[k++] = a[j++];
    }
    for (k = 0, i = s1; i <= e2; k++, i++) {
        a[i] = temp[k];
    }
}

void mergeSort(int a[], int i, int j) {
    int mid = (i + j) / 2;
    if (i < j) {
        mergeSort(a, i, mid);
        mergeSort(a, mid + 1, j);
        merge(a, i, mid, mid + 1, j);
    }
}

int main() {
    int arr[] = {4, 6, 2, 7, 2, 1};
    int size = 6;
    mergeSort(arr, 0, size - 1);
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    return 0;
}