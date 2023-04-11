#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int s) {
    int min;
    for(int i=0; i<s-1; i++) {
        min = i;
        for(int j=i+1; j<s; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

int main() {
    int arr[] = {4,6,2,7,1};
    int size = 5;
    selectionSort(arr, size);
    for(int i=0; i<size; i++) cout<<arr[i]<<" ";
    return 0;
}