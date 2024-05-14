#include <iostream>

class Stack {
private:
    int *stack_array;
    int top;
    int size;

public:
    Stack() : stack_array(nullptr), top(-1), size(0) {}

    Stack(int s) : stack_array(new int[s]), top(-1), size(s) {}

    ~Stack() {
        delete[] stack_array;
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == size - 1;
    }

    bool push(int data) {
        if (isFull()) {
            std::cout << "Stack Overflow!" << std::endl;
            return false;
        }
        stack_array[++top] = data;
        return true;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow!" << std::endl;
            return -1;
        }
        return stack_array[top--];
    }
};

class Queue {
private:
    int *queue_array;
    int front;
    int rear;
    int size;

public:
    Queue() : queue_array(nullptr), front(-1), rear(-1), size(0) {}

    Queue(int s) : queue_array(new int[s]), front(-1), rear(-1), size(s) {}

    ~Queue() {
        delete[] queue_array;
    }

    bool isEmpty() const {
        return front == -1 && rear == -1;
    }

    bool isFull() const {
        return (rear + 1) % size == front;
    }

    bool enqueue(int data) {
        if (isFull()) {
            std::cout << "Queue Overflow!" << std::endl;
            return false;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        queue_array[rear] = data;
        return true;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue Underflow!" << std::endl;
            return -1;
        }
        int data = queue_array[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        return data;
    }
};

int main() {
    Stack stack(5);
    Queue queue(5);

    for (int i = 1; i <= 5; ++i) {
        stack.push(i * 10);
    }

    while (!stack.isEmpty()) {
        std::cout << "Popped from stack: " << stack.pop() << std::endl;
    }

    for (int i = 1; i <= 5; ++i) {
        queue.enqueue(i * 10);
    }

    while (!queue.isEmpty()) {
        std::cout << "Dequeued from queue: " << queue.dequeue() << std::endl;
    }

    return 0;
}
