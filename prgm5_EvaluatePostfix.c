#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
#define MAX_SIZE 100 
 
// Structure to represent a stack 
typedef struct { 
    int top; 
    int array[MAX_SIZE]; 
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
 
// Function to push an element onto the stack 
void push(Stack* stack, int item) { 
    stack->array[++stack->top] = item; 
} 
 
// Function to pop an element from the stack 
int pop(Stack* stack) { 
    if (!isEmpty(stack)) 
        return stack->array[stack->top--]; 
    return -1; // Return -1 if the stack is empty 
} 
 
// Function to evaluate postfix expression  
int evaluatePostfix(char* expression) { 
    Stack* stack = createStack(); 
    int i, operand1, operand2; 
    for (i = 0; expression[i]; ++i) { 
        char ch = expression[i]; 
        if (isdigit(ch)) 
            push(stack, ch - '0'); // Convert char to int 
        else { // Operator 
            operand2 = pop(stack); 
            operand1 = pop(stack); 
            switch (ch) { 
                case '+': push(stack, operand1 + operand2); break; 
                case '-': push(stack, operand1 - operand2); break; 
                case '*': push(stack, operand1 * operand2); break; 
                case '/': push(stack, operand1 / operand2); break; 
            } 
        } 
    } 
    return pop(stack); 
} 
 
// Main function 
    int main() { 
    char expression[MAX_SIZE]; 
    printf("Enter a valid postfix expression: "); 
    fgets(expression, MAX_SIZE, stdin); 
 
 
 
    // Remove newline character from input 
    expression[strcspn(expression, "\n")] = '\0'; 
 
    int result = evaluatePostfix(expression); 
    printf("Result: %d\n", result); 
    return 0; 
} 