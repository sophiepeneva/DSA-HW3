# DSA-HW3

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void merge(long long*& arr, int left, int middle, int right) {
    int leftIndex = left;
    int rightIndex = middle + 1;
    long long* temp = new long long[right - left + 1];
    int index = 0;
    while (leftIndex <= middle && rightIndex <= right) {
        if (arr[leftIndex] <= arr[rightIndex]) {
            temp[index++] = arr[leftIndex++];
        }
        else {
            temp[index++] = arr[rightIndex++];
        }
    }
    if (leftIndex > middle)for (int i = index;i < right - left + 1;i++)temp[i] = arr[rightIndex++];
    else { for (int i = index;i < right - left + 1;i++)temp[i] = arr[leftIndex++]; }
    int counter = 0;
    for (int i = left;i < right + 1;i++)arr[i] = temp[counter++];
}

void mergeSort(long long*& arr, int left, int right) {
    if(left >= right) return;
    int middle = (right + left) / 2;
    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);
    merge(arr, left, middle, right);
}

void binarySearch(long long* arr, int left,int right, long long num, int& index, bool lookingForFirstIndex) {
    if (left > right) return;
    int middle = (left + right) / 2;
    if (arr[middle] == num) {
        index = middle + 1;
        if(lookingForFirstIndex)binarySearch(arr, left, middle - 1, num, index,lookingForFirstIndex);
        else { binarySearch(arr, middle + 1, right, num, index, lookingForFirstIndex); }
    }
    if (arr[middle] > num)binarySearch(arr, left, middle - 1, num, index,lookingForFirstIndex);
    if (arr[middle] < num)binarySearch(arr, middle + 1, right, num, index,lookingForFirstIndex);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    int n;
    cin >> n;
    long long* arr = new long long[n];
    for (int i = 0;i < n;i++) {
        cin>>arr[i];
    }
    mergeSort(arr, 0, n-1);
    int q;
    cin >> q;
    long long* queries = new long long[q];
    for (int i = 0;i < q;i++)cin>>queries[i];
    for (int i = 0;i < q;i++) {
        int index = -1;
        binarySearch(arr, 0, n - 1, queries[i],index,true);
        int lastIndex = -1;
        binarySearch(arr, 0, n - 1, queries[i], lastIndex, false);
        cout << index << " " << lastIndex << endl;
    }
    return 0;
}
