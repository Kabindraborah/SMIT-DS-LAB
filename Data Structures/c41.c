#include <stdio.h>

#define MAX_SIZE 100

struct Stack {
  int data[MAX_SIZE];
  int top;
};

void push(struct Stack *stack, int item) {
  if (stack->top == MAX_SIZE - 1) { // top = -1 and say max size was 3 ... 0,1,2 now if you try to push once again it will show an stack overflow
    printf("Stack overflow\n");
    return;
  }

  stack->data[++stack->top] = item;
} 

int pop(struct Stack *stack) {
  if (stack->top == -1) {
    printf("Stack underflow\n");
    return -1;
  }

  return stack->data[stack->top--];
}

int peek(struct Stack *stack) {
  if (stack->top == -1) {
    printf("Stack is empty\n");
    return -1;
  }

  return stack->data[stack->top];
}

void display(struct Stack *stack) {
  if (stack->top == -1) {
    printf("Stack is empty\n");
    return;
  }

  for (int i = stack->top; i >= 0; i--) {
    printf("%d ", stack->data[i]);
  }
  printf("\n");
}

int main() {
  struct Stack stack;
  stack.top = -1; // Initialize the stack as empty

  int choice;
  int item; // Declare these variables outside the switch

  while (1) {
    printf("Select an operation:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Display\n");
    printf("5. Exit\n");

    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the item to push: ");
        scanf("%d", &item);
        push(&stack, item);
        break;
      case 2:
        item = pop(&stack); // Assign the result of pop() to 'item'
        if (item != -1) {
          printf("The item popped is: %d\n", item);
        }
        break;
      case 3:
        item = peek(&stack); // Assign the result of peek() to 'item'
        if (item != -1) {
          printf("The top item is: %d\n", item);
        }
        break;
      case 4:
        display(&stack);
        break;
      case 5:
        return 0;
      default:
        printf("Invalid choice\n");
        break;
    }
  }

  return 0;
}
