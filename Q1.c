#include <stdio.h>

int main() {
    int i, n, sum = 0, max = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements: \n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n; i++) {
        sum += arr[i]; 
        
        if(sum > max) {
            max = sum;
        }
        
        
        if(sum < 0) {
            sum = 0;
        }
    }

    printf("The highest possible sum of your subarray is: %d\n", max);

    return 0;
}
