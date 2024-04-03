#include <iostream>

const int MAX_SIZE = 100; // Maximum size of the stack

struct Stack {
    int top;
    int data[MAX_SIZE];

    Stack() {
        top = -1; // Initialize top to -1 indicating an empty stack
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int value) {
        if (isFull()) {
            std::cout << "Stack Overflow! Cannot push more elements.\n";
            return;
        }
        data[++top] = value; // Increment top and then insert value
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow! Cannot pop from an empty stack.\n";
            return -1; // Return some default value indicating failure
        }
        return data[top--]; // Return top element and then decrement top
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty.\n";
            return -1; // Return some default value indicating failure
        }
        return data[top]; // Return top element without removing it
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top element: " << stack.peek() << std::endl;

    std::cout << "Popping elements: ";
    while (!stack.isEmpty()) {
        std::cout << stack.pop() << " ";
    }
    std::cout << std::endl;

    return 0;
}