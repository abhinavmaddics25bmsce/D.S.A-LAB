#include <stdio.h>

char stack[10001];
int top = -1;


void push(char item) {
    stack[++top] = item;
}

char pop() {
    return stack[top--];
}

int main() {
    char s[10001];

    printf("Enter a string of brackets: ");
    scanf("%10000s", s);

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        if (c == '(' || c == '{' || c == '[') {
            push(c);
        }

        else {
            if (top == -1) {
                printf("Result: The string is invalid.\n");
                return 0;
            }

            else {
                char top_bracket = pop();

                if ((c == ')' && top_bracket != '(') ||
                    (c == '}' && top_bracket != '{') ||
                    (c == ']' && top_bracket != '[')) {
                    printf("Result: The string is invalid.\n");
                    return 0;
                }
            }

        }
    }

    if (top != -1) {
        printf("Result: The string is invalid.\n");
        return 0;
    }

    printf("Result: The string is valid.\n");
    return 0;
}

