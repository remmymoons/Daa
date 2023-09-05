#include <iostream>

class HeapSort {
public:
    void heapify(int a[], int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && a[left] > a[largest])
            largest = left;

        if (right < n && a[right] > a[largest])
            largest = right;

        if (largest != i) {
            int temp = a[i];
            a[i] = a[largest];
            a[largest] = temp;
            heapify(a, n, largest);
        }
    }

    void heapSort(int a[], int n) {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(a, n, i);

        for (int i = n - 1; i >= 0; i--) {
            int temp = a[0];
            a[0] = a[i];
            a[i] = temp;
            heapify(a, i, 0);
        }
    }

    void printArr(int arr[], int n) {
        for (int i = 0; i < n; ++i) {
            std::cout << arr[i] << " ";
        }
    }

    void sort(int a[], int n) {
        heapSort(a, n);
    }
};

int main() {
    int a[] = {48, 10, 23, 43, 28, 26, 1};
    int n = sizeof(a) / sizeof(a[0]);

    HeapSort heapSort;
    
    std::cout << "Before sorting array elements are - \n";
    heapSort.printArr(a, n);

    heapSort.sort(a, n);

    std::cout << "\nAfter sorting array elements are - \n";
    heapSort.printArr(a, n);

    return 0;
}
