#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct {    
  char data[MAX_SIZE];    
  int top;
}  Stack;

void initStack(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

bool isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, char value) {
    if (isFull(s)) return;
    s->data[++(s->top)] = value;
}

char pop(Stack *s) {
    if (isEmpty(s)) return '\0';
    return s->data[(s->top)--];
}


bool checkParentheses(char *exp) {




}




int main(void) {
    char *test1 = "((3 + 5) * (2 - 1))";
    char *test2 = "((3 + 5) * (2 - 1)";
    char *test3 = "(3 + 5) * 2 - 1)";

    char *tests[] = {test1, test2, test3};

    for (int i = 0; i < 3; i++) {
        printf("Test %d: \"%s\"\n", i + 1, tests[i]);
        if (checkParentheses(tests[i])) {
            printf("Valid\n\n");
        } else {
            printf("Invalid\n\n");
        }
    }
}

