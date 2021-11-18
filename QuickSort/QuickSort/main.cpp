#include<stdio.h>
#include<vector>
using namespace std;

void swap(int &n1, int &n2)
{
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

int partition (vector<int> &v, int min, int max)
{
    int pivot = v[max];
    int i = min-1;
    for (int j = min; j < max; j++)
    {
        if (v[j] <= pivot)
        {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i+1], v[max]);
    return i++;
}

void quickSort(vector<int> &v, int min, int max)
{
    if (min < max)
    {
        int mid = partition(v, min, max);
        quickSort(v, min, mid-1);
        quickSort(v, mid+1, max);
    }
}

int main()
{
    vector<int> v = { 10, 7, 8, 9, 1, 5 };
    
    printf("Before QuickSort\n");
    for (int i = 0; i < v.size(); i++)
        printf("%d ", v[i]);
    printf("\n");
    
    int n = sizeof(v)/sizeof(v[0]);
    quickSort(v, 0, n-1);
    
    printf("After QuickSort\n");
    for (int i = 0; i < v.size(); i++)
        printf("%d ", v[i]);
    printf("\n");
}
