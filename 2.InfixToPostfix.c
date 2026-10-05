#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    if (top < MAX - 1) {
        stack[++top] = item;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

int precedence(char symbol) {
    if (symbol == '^') {
        return 3;
    }
    else if (symbol == '*' || symbol == '/') {
        return 2;
    }
    else if (symbol == '+' || symbol == '-') {
        return 1;
    }
    else{
        return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char item;

    while (infix[i] != '\0') {
        item = infix[i];

        if (isalnum(item)) {
            postfix[j++] = item;
        }

        else if (item == '(') {
            push(item);
        }
        else if (item == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();
        }
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(item)) {
                postfix[j++] = pop();
            }
            push(item);
        }
        i++;
    }
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter a valid infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
