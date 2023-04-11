#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int s) {
    
    for(int i=s-1; i>=0; i--) {
        bool flag = 0;
        for(int j=0; j<i; j++) {
            if(arr[j] > arr[j+1]) {
                flag = 1;
                swap(arr[j], arr[j+1]);
            }
        }
        if(flag == 0) break;
    }
}

int main() {
    int arr[] = {4,6,2,7,1};
    int size = 5;
    bubbleSort(arr, size);
    for(int i=0; i<size; i++) cout<<arr[i]<<" ";
    return 0;
}

