#include<stdio.h>
#include<stdlib.h>

struct CHAR_QUEUE {
    char *arr;
    int size, front, rear;
};

struct STACK {
    char *arr;
    int top;
    int size;
};

struct CHAR_QUEUE* CREATE_CHAR_QUEUE(int size) {
    struct CHAR_QUEUE *q = (struct CHAR_QUEUE*)malloc(sizeof(struct CHAR_QUEUE));
    q->size = size;
    q->front = -1;
    q->rear = -1;
    q->arr = (char*)malloc(size * sizeof(char));
    return q;
}

struct STACK* CREATE_STACK(int size) {
    struct STACK *s = (struct STACK*)malloc(sizeof(struct STACK));
    s->size = size;
    s->top = -1;
    s->arr = (char*)malloc(size * sizeof(char));
    return s;
}

int IS_EMPTY_QUEUE(struct CHAR_QUEUE* q) {
    return (q->front == -1 && q->rear == -1);
}

int IS_FULL_QUEUE(struct CHAR_QUEUE* q) {
    return (q->rear == q->size - 1);
}

void ENQUEUE_CHAR_QUEUE(struct CHAR_QUEUE* q, char x) {
    if (IS_FULL_QUEUE(q)) {
        printf("Queue is full....\n");
        return;
    } else if (q->front == -1 && q->rear == -1) {
        q->front = q->rear = 0;
        q->arr[q->rear] = x;
    } else {
        q->rear++;
        q->arr[q->rear] = x;
    }
}

char DEQUEUE_CHAR_QUEUE(struct CHAR_QUEUE* q) {
    if (IS_EMPTY_QUEUE(q)) {
        printf("Queue is empty.\n");
        return '\0';  
    } else {
        char removed = q->arr[q->front];
        if (q->front == q->rear) {
            q->front = q->rear = -1;
        } else {
            q->front++;
        }
        return removed;
}}

void FRONT_CHAR_QUEUE(struct CHAR_QUEUE* q) {
    if (IS_EMPTY_QUEUE(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Front element: %c\n", q->arr[q->front]);
    }
}

void DISPLAY_CHAR_QUEUE(struct CHAR_QUEUE* q) {
    if (IS_EMPTY_QUEUE(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements:\n");
        for (int i = q->front; i <= q->rear; i++) {
            printf("| %c |\n", q->arr[i]);
        }
    }
}

void DESTROY_CHAR_QUEUE(struct CHAR_QUEUE* q) {
    free(q->arr);
    free(q);
}

void REVERSE_QUEUE(struct CHAR_QUEUE* q) {
    struct STACK *stack=CREATE_STACK(q->size);

    while (!IS_EMPTY_QUEUE(q)) {
        char element = DEQUEUE_CHAR_QUEUE(q);
        stack->arr[++stack->top] = element;
    }

    while (stack->top != -1) {
        char element = stack->arr[stack->top--];
        ENQUEUE_CHAR_QUEUE(q, element);
    }

    free(stack->arr);
    free(stack);
}

int main() {
    struct CHAR_QUEUE *queue = CREATE_CHAR_QUEUE(5);

    ENQUEUE_CHAR_QUEUE(queue, 'A');
    ENQUEUE_CHAR_QUEUE(queue, 'B');
    ENQUEUE_CHAR_QUEUE(queue, 'C');
    ENQUEUE_CHAR_QUEUE(queue, 'D');
    ENQUEUE_CHAR_QUEUE(queue, 'E');

    printf("Queue before reversal:\n");
    DISPLAY_CHAR_QUEUE(queue);

    REVERSE_QUEUE(queue);

    printf("\nQueue after reversal:\n");
    DISPLAY_CHAR_QUEUE(queue);

    DESTROY_CHAR_QUEUE(queue);

    return 0;
}
