#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100


char stack[MAX_SIZE];
int top = -1;

void push(char c) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack[top--];
}

bool is_valid(char* s) {
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(s[i]);
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            char c = pop();
            if ((s[i] == ')' && c != '(') ||
                (s[i] == '}' && c != '{') ||
                (s[i] == ']' && c != '[')) {
                return false;
            }
        }
    }
    return (top == -1);
}

int main() {
    char s[MAX_SIZE];
    printf("Enter a string of parentheses: ");
    scanf("%s", s);
    if (is_valid(s)) {
        printf("Valid\n");
    }
    else {
        printf("Invalid\n");
    }
    return 0;
}
