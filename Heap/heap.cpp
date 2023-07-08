#include <bits/stdc++.h>
using namespace std;

class heap
{

private:
    int arr[100];
    int size = -1;

public:
    heap()
    {
        size = -1;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;

        arr[index] = val;

        while (index > 0)
        {
            int parent = (index - 1) >> 1;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                return;
        }
    }

    void deleteFromHeap()
    {
        // replace the last element with root

        if (size == -1)
        {
            cout << "Heap is Empty";
            return;
        }

        arr[0] = arr[size];

        // as now root is at last and we need to delete it , decrement the size
        --size;

        // bring root to its correct position

        int idx = 0;

        while (idx <= size)
        {
            int leftIdx = (2 * idx) + 1;
            int rightIdx = (2 * idx) + 2;

            if (idx <= size and arr[idx] < arr[leftIdx])
            {
                if (arr[leftIdx] > arr[rightIdx])
                {
                    swap(arr[idx], arr[leftIdx]);
                    idx = leftIdx;
                }
                else
                {
                    swap(arr[idx], arr[rightIdx]);
                    idx = rightIdx;
                }
            }
            else if (idx <= size and arr[idx] < arr[rightIdx])
            {
                swap(arr[idx], arr[rightIdx]);
                idx = rightIdx;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 0; i <= size; ++i)
            cout << arr[i] << ' ';
        cout << endl;
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    if (left < n and arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n and arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int size = n;

    while (size > 0)
    {
        swap(arr[0], arr[size-1]);

        --size;

        heapify(arr, size, 0);
    }
}

int main()
{
    heap h;

    cout<<"Inserting"<<endl;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    h.deleteFromHeap();

    cout<<"Delete"<<endl;
    h.print();

    int arr[5] = {54, 53, 55, 52, 50};

    int n = 5;

    // heap creation

    for (int i = (n / 2)-1; i >= 0; --i)
    {
        heapify(arr, n, i);
    }

    cout << "After Heapify" << endl;
    for (int i = 0; i < n; ++i)
        cout << arr[i] << ' ';
    cout << endl;

    heapSort(arr, n);

    cout << "Heap Sort" << endl;
    for (int i = 0; i < n; ++i)
        cout << arr[i] << ' ';
    cout << endl;
}