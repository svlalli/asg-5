#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int value) 
{
    if (rear == MAX_SIZE - 1)
     {
        printf("Queue is full. Cannot enqueue element.\n");
    } else 
    {
        if (front == -1)
         {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("Enqueued element: %d\n", value);
    }
}

void dequeue() 
{
    if (front == -1 || front > rear)
     {
        printf("Queue is empty. Cannot dequeue element.\n");
    } else 
    {
        printf("Dequeued element: %d\n", queue[front]);
        front++;
    }
}

void display() 
{
    if (front == -1 || front > rear) 
    {
        printf("Queue is empty.\n");
    } else 
    {
        printf("Elements in the queue are: ");
        for (int i = front; i <= rear; i++)
         {
            printf("%d ", queue[i]);
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
