/*Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise.*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int size;
    int capacity;
} MyCircularDeque;

MyCircularDeque* createDeque(int k) {
    MyCircularDeque* dq = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    dq->front = -1;
    dq->rear = -1;
    dq->size = 0;
    dq->capacity = k;
    return dq;
}

bool isEmpty(MyCircularDeque* dq) {
    return dq->size == 0;
}

bool isFull(MyCircularDeque* dq) {
    return dq->size == dq->capacity;
}

bool insertFront(MyCircularDeque* dq, int value) {
    if(isFull(dq))
        return false;

    if(isEmpty(dq)) {
        dq->front = dq->rear = 0;
    }
    else {
        dq->front = (dq->front - 1 + dq->capacity) % dq->capacity;
    }

    dq->arr[dq->front] = value;
    dq->size++;
    return true;
}

bool insertLast(MyCircularDeque* dq, int value) {
    if(isFull(dq))
        return false;

    if(isEmpty(dq)) {
        dq->front = dq->rear = 0;
    }
    else {
        dq->rear = (dq->rear + 1) % dq->capacity;
    }

    dq->arr[dq->rear] = value;
    dq->size++;
    return true;
}

bool deleteFront(MyCircularDeque* dq) {
    if(isEmpty(dq))
        return false;

    if(dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    }
    else {
        dq->front = (dq->front + 1) % dq->capacity;
    }

    dq->size--;
    return true;
}

bool deleteLast(MyCircularDeque* dq) {
    if(isEmpty(dq))
        return false;

    if(dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    }
    else {
        dq->rear = (dq->rear - 1 + dq->capacity) % dq->capacity;
    }

    dq->size--;
    return true;
}

int getFront(MyCircularDeque* dq) {
    if(isEmpty(dq))
        return -1;
    return dq->arr[dq->front];
}

int getRear(MyCircularDeque* dq) {
    if(isEmpty(dq))
        return -1;
    return dq->arr[dq->rear];
}
