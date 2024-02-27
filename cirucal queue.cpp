#include <stdio.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if ((front == 0 && rear == MAX_SIZE - 1) || (rear == front - 1)) {
        printf("Queue is full. Cannot enqueue element.\n");
    } else {
        if (rear == MAX_SIZE - 1 && front != 0) {
            rear = -1;
        }
        rear++;
        queue[rear] = value;
        if (front == -1) {
            front = 0;
        }
        printf("Enqueued element: %d\n", value);
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty. Cannot dequeue element.\n");
    } else {
        printf("Dequeued element: %d\n", queue[front]);
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == MAX_SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Elements in the queue are: ");
        int i = front;
        if (front <= rear) {
            while (i <= rear) {
                printf("%d ", queue[i]);
                i++;
            }
        } else {
            while (i <= MAX_SIZE - 1) {
                printf("%d ", queue[i]);
                i++;
            }
            i = 0;
            while (i <= rear) {
                printf("%d ", queue[i]);
                i++;
            }
        }
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}
