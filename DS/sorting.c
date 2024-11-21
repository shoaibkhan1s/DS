#include <stdio.h>

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// **1. Selection Sort** (Simplified)
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        // Find the index of the minimum element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the minimum element with the element at the current index
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// **2. Bubble Sort** (Simplified)
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Compare adjacent elements and swap if needed
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// **3. Insertion Sort** (Simplified)
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // Move elements of arr[0..i-1] that are greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// **4. Merge Sort** (Simplified)
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    // Temporary arrays
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// **5. Quick Sort** (Simplified)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// **6. Heap Sort** (Simplified)
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Selection Sort
    printf("Original array for Selection Sort: ");
    printArray(arr, n);
    selectionSort(arr, n);
    printf("Sorted array using Selection Sort: ");
    printArray(arr, n);

    // Bubble Sort
    int arr2[] = {12, 11, 13, 5, 6, 7};
    printf("\nOriginal array for Bubble Sort: ");
    printArray(arr2, n);
    bubbleSort(arr2, n);
    printf("Sorted array using Bubble Sort: ");
    printArray(arr2, n);

    // Insertion Sort
    int arr3[] = {12, 11, 13, 5, 6, 7};
    printf("\nOriginal array for Insertion Sort: ");
    printArray(arr3, n);
    insertionSort(arr3, n);
    printf("Sorted array using Insertion Sort: ");
    printArray(arr3, n);

    // Merge Sort
    int arr4[] = {12, 11, 13, 5, 6, 7};
    printf("\nOriginal array for Merge Sort: ");
    printArray(arr4, n);
    mergeSort(arr4, 0, n - 1);
    printf("Sorted array using Merge Sort: ");
    printArray(arr4, n);

    // Quick Sort
    int arr5[] = {12, 11, 13, 5, 6, 7};
    printf("\nOriginal array for Quick Sort: ");
    printArray(arr5, n);
    quickSort(arr5, 0, n - 1);
    printf("Sorted array using Quick Sort: ");
    printArray(arr5, n);

    // Heap Sort
    int arr6[] = {12, 11, 13, 5, 6, 7};
    printf("\nOriginal array for Heap Sort: ");
    printArray(arr6, n);
    heapSort(arr6, n);
    printf("Sorted array using Heap Sort: ");
    printArray(arr6, n);

    return 0;
}
