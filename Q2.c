#include <stdio.h>

int main() {
    int n, k, maxLength = 0, zeroCount;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the maximum number of flips (k): ");
    scanf("%d", &k);

    int arr[n];

    printf("Enter the elements of the array (0's and 1's): \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    for (int start = 0; start < n; start++) {
        zeroCount = 0; 
        for (int end = start; end < n; end++) {
        
            if (arr[end] == 0) {
                zeroCount++;
            }

        
            if (zeroCount > k) {
                break;
            }

        
            int length = end - start + 1;

        
            if (length > maxLength) {
                maxLength = length;
            }
        }
    }


    printf("The longest contiguous subarray of 1's after flipping at most %d 0's is: %d\n", k, maxLength);

    return 0;
}
