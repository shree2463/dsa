 #include<stdio.h> 
#include<stdlib.h>  
#include<string.h> 
#include<ctype.h> 
#define MAX_SIZE 100 
 
// Structure to represent a stack 
typedef struct { 
    int top; 
    char array[MAX_SIZE]; 
} Stack; 
 
// Function to create a stack 
Stack* createStack() { 
    Stack* stack = (Stack*)malloc(sizeof(Stack)); 
    stack->top = -1; 
    return stack; 
} 
 
// Function to check if the stack is empty 
int isEmpty(Stack* stack) { 
    return stack->top == -1; 
} 
 
// Function to return the top element of the stack 
char peek(Stack* stack) { 
    return stack->array[stack->top]; 
} 
 
// Function to push an element onto the stack 
void push(Stack* stack, char item) { 
    stack->array[++stack->top] = item; 
} 
 
// Function to pop an element from the stack 
char pop(Stack* stack) { 
    if (!isEmpty(stack)) 
        return stack->array[stack->top--]; 
    return '\0'; // Return null character if the stack is empty 
} 
 
// Function prototype for precedence function 
int precedence(char op); 
 
// Function to convert infix expression to postfix expression 
void infixToPostfix(char* infix, char* postfix) { 
    Stack* stack = createStack(); 
    int i, k; 
    for (i = 0, k = -1; infix[i]; ++i) { 
 
 
        char ch = infix[i]; 
        if (isalnum(ch)) 
            postfix[++k] = ch; 
        else if (ch == '(') 
            push(stack, ch); 
        else if (ch == ')') { 
            while (!isEmpty(stack) && peek(stack) != '(') 
                postfix[++k] = pop(stack); 
            if (!isEmpty(stack) && peek(stack) != '(') 
                return; // Invalid expression 
            else 
                pop(stack); // Discard '(' 
        } else { // Operator 
            while (!isEmpty(stack) && peek(stack) != '(' && precedence(ch) <= 
precedence(peek(stack))) 
                postfix[++k] = pop(stack); 
            push(stack, ch); 
        } 
    } 
    while (!isEmpty(stack)) 
        postfix[++k] = pop(stack); 
    postfix[++k] = '\0'; 
} 
 
// Function to get the precedence of an operator 
int precedence(char op) { 
    if (op == '+' || op == '-') 
        return 1; 
    if (op == '*' || op == '/') 
        return 2; 
    return 0; 
} 
 
// Main function 
int main() { 
    char infix[MAX_SIZE]; 
    printf("Enter an infix expression: "); 
    fgets(infix, MAX_SIZE, stdin); 
 
    // Remove newline character from input 
    infix[strcspn(infix, "\n")] = '\0'; 
 
    char postfix[MAX_SIZE]; 
    infixToPostfix(infix, postfix); 
    printf("Postfix expression: %s\n", postfix); 
    return 0; 
}