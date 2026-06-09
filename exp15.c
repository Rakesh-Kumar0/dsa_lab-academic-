#include <stdio.h>

void rotateLeft(int arr[], int n, int k) {
    int temp[n];
    for (int i = 0; i < n; i++) {
        temp[i] = arr[(i + k) % n];
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");
}

int main() {
    int T;
    printf("Enter the value of sample input: ");
    scanf("%d", &T);
    while (T--) {
        int n, k;
        printf("Enter the value of n and k: ");
        scanf("%d %d", &n, &k);
        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        rotateLeft(arr, n, k);
    }
    return 0;
}