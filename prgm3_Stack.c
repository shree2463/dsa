#include <stdio.h> 
#define MAX_SIZE 100 
// Structure to represent a stack 
typedef struct { 
    int top; 
    int array[MAX_SIZE]; 
} Stack; 
 
 
 
// Function to create an empty stack 
Stack*createStack() { 
    Stack* stack = (Stack*)malloc(sizeof(Stack)); 
    stack->top = -1; 
    return stack; 
} 
 
// Function to check if the stack is empty 
int isEmpty(Stack* stack) { 
    return stack->top == -1; 
} 
 
// Function to check if the stack is full 
int isFull(Stack* stack) { 
    return stack->top == MAX_SIZE - 1; 
} 
 
// Function to push an element onto the stack 
void push(Stack* stack, int item) { 
    if (isFull(stack)) { 
        printf("Stack overflow. Cannot push.\n"); 
        return; 
    } 
    stack->array[++stack->top] = item; 
} 
 
// Function to pop an element from the stack 
int pop(Stack* stack) { 
    if (isEmpty(stack)) { 
        printf("Stack underflow. Cannot pop.\n"); 
        return -1; 
    } 
    return stack->array[stack->top--]; 
} 
 
// Function to display the elements of the stack 
void display(Stack* stack) { 
    if (isEmpty(stack)) { 
        printf("Stack is empty.\n"); 
        return; 
    } 
    printf("Stack elements: "); 
    int i; 
    for (i = stack->top; i >= 0; --i) 
        printf("%d ", stack->array[i]); 
    printf("\n"); 
 
 
} 
 
// Main function 
    int main() { 
    Stack* stack = createStack(); 
    int choice, item; 
 
    do { 
        printf("\nStack Operations:\n"); 
        printf("1. Push\n"); 
        printf("2. Pop\n"); 
        printf("3. Display\n"); 
        printf("4. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter element to push: "); 
                scanf("%d", &item); 
                push(stack, item); 
                break; 
            case 2: 
                item = pop(stack); 
                if (item != -1) 
                    printf("Popped element: %d\n", item); 
                break; 
            case 3: 
                display(stack); 
                break; 
            case 4: 
                printf("Exiting...\n"); 
                break; 
            default: 
                printf("Invalid choice! Please enter a valid option.\n"); 
        } 
    } while (choice != 4); 
 
    return 0; 
} 