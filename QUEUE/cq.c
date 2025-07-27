// // Create a file named “CIRCULAR_queue.c” and implement the following functions to provide a
// // CIRCULARacter queue. Also write a file CIRCULAR_test.c to test the working of CIRCULAR_queue.c
// // a. Declare a structure named CIRCULAR_QUEUE which has a CIRCULARacter pointer to hold a
// // CIRCULARacter array and two integer values for size, front and rear position respectively.
// // b. Implement a CREATE_CIRCULAR_QUEUE function which takes integers as an
// // argument for stack size and returns the pointer to CIRCULAR_QUEUE structure.
// // c. Implement IS_EMPTY_CIRCULAR_QUEUE and IS_FULL_CIRCULAR_QUEUE
// // functions which take CIRCULAR_QUEUE as input and return boolean/ int value.
// // d. Implement ENQUEUE_CIRCULAR_QUEUE function which takes CIRCULAR_QUEUE
// // and a CIRCULARacter X as input to perform insertion into the queue.
// // e. Implement DEQUEUE_CIRCULAR_QUEUE function which takes CIRCULAR_QUEUE
// // and returns a CIRCULARacter as output to perform deletion in the queue.
// // f. Implement FRONT_CIRCULAR_QUEUE to return the front element form
// // CIRCULAR_QUEUE passed as argument.
// // g. Implement DISPLAY_CIRCULAR_QUEUE to display content of CIRCULAR_QUEUE
// // passed as argument.
// // h. Implement DESTROY_CIRCULAR_QUEUE to remove CIRCULAR_QUEUE passed from
// // the memory.


#include <stdio.h>
#include <stdlib.h>

struct CIRCULAR_QUEUE {
    char *arr;
    int size, front, rear;
};

struct CIRCULAR_QUEUE* CREATE_CIRCULAR_QUEUE(int size) {
    struct CIRCULAR_QUEUE *q = (struct CIRCULAR_QUEUE*)malloc(sizeof(struct CIRCULAR_QUEUE));
    q->size = size;
    q->front = -1;
    q->rear = -1;
    q->arr = (char*)malloc(size * sizeof(char));
    return q;
}

int IS_EMPTY_QUEUE(struct CIRCULAR_QUEUE* q) {
    return q->front == -1;
}

int IS_FULL_QUEUE(struct CIRCULAR_QUEUE* q) {
    return (q->rear + 1) % q->size == q->front;
}

void ENQUEUE_CIRCULAR_QUEUE(struct CIRCULAR_QUEUE* q, char x) {
    if (IS_FULL_QUEUE(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (IS_EMPTY_QUEUE(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = x;
}

void DEQUEUE_CIRCULAR_QUEUE(struct CIRCULAR_QUEUE* q) {
    if (IS_EMPTY_QUEUE(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Dequeued element: %c\n", q->arr[q->front]);
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }
}

void FRONT_CIRCULAR_QUEUE(struct CIRCULAR_QUEUE* q) {
    if (IS_EMPTY_QUEUE(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Front element: %c\n", q->arr[q->front]);
}

void DISPLAY_CIRCULAR_QUEUE(struct CIRCULAR_QUEUE* q) {
    if (IS_EMPTY_QUEUE(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%c ", q->arr[i]);
        if (i == q->rear) break;
        i = (i + 1) % q->size;
    }
    printf("\n");
}

void DESTROY_CIRCULAR_QUEUE(struct CIRCULAR_QUEUE* q) {
    free(q->arr);
    free(q);
}

int main() {
    struct CIRCULAR_QUEUE *queue = CREATE_CIRCULAR_QUEUE(5);
    
    ENQUEUE_CIRCULAR_QUEUE(queue, 'A');
    ENQUEUE_CIRCULAR_QUEUE(queue, 'B');
    ENQUEUE_CIRCULAR_QUEUE(queue, 'C');
    ENQUEUE_CIRCULAR_QUEUE(queue, 'D');
    ENQUEUE_CIRCULAR_QUEUE(queue, 'E');
    
    DISPLAY_CIRCULAR_QUEUE(queue);
    
    DEQUEUE_CIRCULAR_QUEUE(queue);
    ENQUEUE_CIRCULAR_QUEUE(queue, 'F');

    FRONT_CIRCULAR_QUEUE(queue);
    
    DISPLAY_CIRCULAR_QUEUE(queue);
    
    DESTROY_CIRCULAR_QUEUE(queue);
    
    return 0;
}
