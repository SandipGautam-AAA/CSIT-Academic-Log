#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 50

char operator[MAX];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX - 1;
}

void push(char x) {
    if (!isFull())
        operator[++top] = x;
    else
        printf("Operator Stack Overflow\n");
}

char pop() {
    if (!isEmpty())
        return operator[top--];
    else {
        printf("Operator Stack Underflow\n");
        return '\0';
    }
}

int priority(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return -1;
}

int main() {
    char infix[MAX], prefix[MAX];
    int k = 0;
    char x;

    printf("Enter the Infix Expression: ");
    scanf("%s", infix);

    strrev(infix);

    for (int i = 0; infix[i] != '\0'; i++) {

        if (isalnum(infix[i])) {
            prefix[k++] = infix[i];
        }

        else if (infix[i] == ')') {
            push(infix[i]);
        }

        else if (infix[i] == '(') {
            while ((x = pop()) != ')') {
                prefix[k++] = x;
            }
        }

        else {
            while (!isEmpty() && priority(operator[top]) > priority(infix[i])) {
                prefix[k++] = pop();
            }
            push(infix[i]);
        }
    }

    while (!isEmpty()) {
        prefix[k++] = pop();
    }

    prefix[k] = '\0';
    strrev(prefix);

    printf("Prefix Expression: %s\n", prefix);

    return 0;
}
