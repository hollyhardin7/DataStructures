#include <iostream>
#include <math.h>
#include <limits.h>
#include <vector>
using namespace std;

class Heap
{
public:
    int heapsize;
    vector <int> vals;
    int parent(int i) { return floor((i-1)/2); };
    int left(int i) { return 2*i; };
    int right(int i) { return (2*i) + 1; };
    void BuildMaxHeap();
    void MaxHeapify(int i);
    void Sort();
    int ExtractMax();
    void IncreaseKey(int i, int k);
    void Insert(int key);
};

void Heap::BuildMaxHeap()
{
    heapsize = (int) vals.size() - 1;
    for (int i = floor(heapsize/2); i >= 0; i--)
        MaxHeapify(i);
}

void Heap::MaxHeapify(int i)
{
    int l = left(i)+1;
    int r = right(i)+1;
    int largest = INT_MIN;
    
    if (l <= heapsize && vals[l] > vals[i])
        largest = l;
    else
        largest = i;
    
    if (r <= heapsize && vals[r] > vals[largest])
        largest = r;
    else {}
    
    if (largest != i)
    {
        swap(vals[i], vals[largest]);
        MaxHeapify(largest);
    }
}

void Heap::Sort()
{
    BuildMaxHeap();
    for (int i = ((int) vals.size()-1); i >= 0; i--)
    {
        swap(vals[0], vals[i]);
        heapsize--;
        MaxHeapify(0);
    }
}

int Heap::ExtractMax()
{
    if (heapsize < 0)
        printf("ERROR");
    int max = vals[0];
    vals[0] = vals[heapsize];
    vals.pop_back();
    heapsize--;
    MaxHeapify(0);
    return max;
}

void Heap::IncreaseKey(int i, int key)
{
    if (key < vals[i])
        printf("ERROR\n");
    
    vals[i] = key;

    while (i > 0 && vals[parent(i)] < vals[i])
    {
        swap(vals[i], vals[parent(i)]);
        i = parent(i);
    }
}

void Heap::Insert(int key)
{
    vals.push_back(INT_MIN);
    heapsize++;
    IncreaseKey(heapsize, key);
}

int main(int argc, const char * argv[])
{
    Heap heap;
    heap.vals.push_back(16);
    heap.vals.push_back(4);
    heap.vals.push_back(10);
    heap.vals.push_back(14);
    heap.vals.push_back(7);
    heap.vals.push_back(9);
    heap.vals.push_back(3);
    heap.vals.push_back(2);
    heap.vals.push_back(8);
    heap.vals.push_back(1);

    heap.BuildMaxHeap();
    printf("After calling BuildMaxHeap\n");
    for (int i = 0; i < heap.vals.size(); i++)
        printf("%d\n", heap.vals[i]);

    int max = heap.ExtractMax();
    printf("\nAfter calling ExtractMax, which returns %d\n", max);
    for (int i = 0; i < heap.vals.size(); i++)
        printf("%d\n", heap.vals[i]);
    
    printf("\nAfter increasing vals[8] == %d to 11\n", heap.vals[8]);
    heap.IncreaseKey(8,11);
    for (int i = 0; i < heap.vals.size(); i++)
        printf("%d\n", heap.vals[i]);
    
    heap.Insert(5);
    printf("\nAfter inserting 5\n");
    for (int i = 0; i < heap.vals.size(); i++)
        printf("%d\n", heap.vals[i]);
    
    heap.Sort();
    printf("\nAfter calling Sort\n");
    for (int i = 0; i < heap.vals.size(); i++)
        printf("%d\n", heap.vals[i]);

    return 0;
}
