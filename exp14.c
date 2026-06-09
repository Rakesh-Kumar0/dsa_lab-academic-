#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100


typedef struct {
    char data[MAX];
    int top;
} Stack;

void push(Stack *s, char ch) {
    if (s->top < MAX - 1) {
        s->data[++(s->top)] = ch;
    }
}

char pop(Stack *s) {
    if (s->top >= 0) {
        return s->data[(s->top)--];
    }
    return '\0';
}

char peek(Stack *s) {
    if (s->top >= 0) {
        return s->data[s->top];
    }
    return '\0';
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void infixToRPN(char *infix, char *rpn) {
    Stack s;
    s.top = -1;
    int j = 0;
    
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        
        if (isalnum(ch)) {
            rpn[j++] = ch;
        } else if (ch == '(') {
            push(&s, ch);
        } else if (ch == ')') {
            while (s.top != -1 && peek(&s) != '(') {
                rpn[j++] = pop(&s);
            }
            pop(&s); 
        } else if (isOperator(ch)) {
            while (s.top != -1 && precedence(peek(&s)) >= precedence(ch) && peek(&s) != '(') {
                rpn[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }
    
    while (s.top != -1) {
        rpn[j++] = pop(&s);
    }
    rpn[j] = '\0';
}

int main() {
    int n;
    printf("Enter number of input:");
    scanf("%d", &n);
    getchar();
    
    char infix[n][MAX], rpn[n][MAX];
    
    for (int i = 0; i < n; i++) {
        scanf("%s", infix[i]);
    }
    
    for (int i = 0; i < n; i++) {
        infixToRPN(infix[i], rpn[i]);
    }
    
    for (int i = 0; i < n; i++) {
        printf("%s\n", rpn[i]);
    }
    
    return 0;
}
