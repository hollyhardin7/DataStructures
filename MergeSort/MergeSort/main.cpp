#include <iostream>
using namespace std;
 
void merge(int arr[], int left, int mid, int right)
{
    int leftMax = mid - left + 1;
    int rightMax = right - mid;
  
    int *leftArr = new int[leftMax];
    int *rightArr = new int[rightMax];
  
    for (int i = 0; i < leftMax; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < rightMax; i++)
        rightArr[i] = arr[mid + 1 + i];
  
    int leftIndex = 0;
    int rightIndex = 0;
    int index = left;
 
    while (leftIndex < leftMax && rightIndex < rightMax)
    {
        if (leftArr[leftIndex] <= rightArr[rightIndex])
        {
            arr[index] = leftArr[leftIndex];
            leftIndex++;
        }
        else
        {
            arr[index] = rightArr[rightIndex];
            rightIndex++;
        }
        index++;
    }
    while (leftIndex < leftMax)
    {
        arr[index] = leftArr[leftIndex];
        leftIndex++;
        index++;
    }
    while (rightIndex < rightMax)
    {
        arr[index] = rightArr[rightIndex];
        rightIndex++;
        index++;
    }
}

void mergeSort(int arr[], int min, int max)
{
    if (min >= max)
        return;
  
    int mid = min + (max-min) / 2;
    mergeSort(arr, min, mid);
    mergeSort(arr, mid + 1, max);
    merge(arr, min, mid, max);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
  
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Before MergeSort\n";
    printArray(arr, size);
    mergeSort(arr, 0, size-1);
    cout << "After MergeSort\n";
    printArray(arr, size);
    return 0;
}
