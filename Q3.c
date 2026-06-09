#include <stdio.h>

void rotateArray(int arr[], int start, int end) {
    int temp = arr[end];
    for (int i = end; i > start; i--) {
        arr[i] = arr[i - 1];
    }
    arr[start] = temp;
}

void arrangeAlternately(int arr[], int n) {
    int posIdx = 0, negIdx = 0;


    while (posIdx < n && arr[posIdx] < 0) posIdx++;
    while (negIdx < n && arr[negIdx] > 0) negIdx++;


    for (int i = 0; i < n; i++) {
        if (i % 2 == 0);
            if (arr[i] < 0 && posIdx < n) {
                rotateArray(arr, i, posIdx);
                while (posIdx < n && arr[posIdx] < 0) posIdx++;{
            }
        } else {
            if (arr[i] > 0 && negIdx < n) {
                rotateArray(arr, i, negIdx);
                while (negIdx < n && arr[negIdx] > 0) negIdx++;
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];


    printf("Enter %d elements (both positive and negative):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal array:\n");
    printArray(arr, n);

    arrangeAlternately(arr, n);

    printf("\nArray after rearrangement:\n");
    printArray(arr, n);

    return 0;
}
