#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

int isValidParentheses(char *s) {
    int balance = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            balance++;
        } else if (s[i] == ')') {
            balance--;
            if (balance < 0) {
                return 0; 
            }
        }
    }
    return balance == 0;
}

int main() {
    int T;
    printf("Enter numbers of input:");
    scanf("%d", &T);
    getchar(); 
    
    char S[T][MAX_LEN];
    
    for (int i = 0; i < T; i++) {
        fgets(S[i], MAX_LEN, stdin);
        S[i][strcspn(S[i], "\n")] = 0; 
    }
    
    for (int i = 0; i < T; i++) {
        if (isValidParentheses(S[i])) {
            printf("valid\n");
        } else {
            printf("invalid\n");
        }
    }
    
    return 0;
}







// #include <stdio.h>
// #include <string.h>

// #define MAX_LEN 1000

// int isValidParentheses(char *s) {
//     int balance = 0;
//     for (int i = 0; s[i] != '\0'; i++) {
//         if (s[i] == '(') {
//             balance++;
//         } else if (s[i] == ')') {
//             balance--;
//             if (balance < 0) {
//                 return 0; 
//             }
//         }
//     }
//     return balance == 0;
// }

// int main() {
//     int T;
//     printf("Enter number of input:");
//     scanf("%d", &T);
//     getchar();
    
//     while (T--) {
//         char S[MAX_LEN];
//         fgets(S, MAX_LEN, stdin);
//         S[strcspn(S, "\n")] = 0; 
        
//         if (isValidParentheses(S)) {
//             printf("valid\n");
//         } else {
//             printf("invalid\n");
//         }
//     }
//     return 0;
// }