// Create a file named “char_queue.c” and implement the following functions to provide a
// character queue. Also write a file char_test.c to test the working of char_queue.c
// a. Declare a structure named CHAR_QUEUE which has a character pointer to hold a
// character array and two integer values for size, front and rear position respectively.
// b. Implement a CREATE_CHAR_QUEUE function which takes integers as an
// argument for stack size and returns the pointer to CHAR_QUEUE structure.
// c. Implement IS_EMPTY_CHAR_QUEUE and IS_FULL_CHAR_QUEUE
// functions which take CHAR_QUEUE as input and return boolean/ int value.
// d. Implement ENQUEUE_CHAR_QUEUE function which takes CHAR_QUEUE
// and a character X as input to perform insertion into the queue.
// e. Implement DEQUEUE_CHAR_QUEUE function which takes CHAR_QUEUE
// and returns a character as output to perform deletion in the queue.
// f. Implement FRONT_CHAR_QUEUE to return the front element form
// CHAR_QUEUE passed as argument.
// g. Implement DISPLAY_CHAR_QUEUE to display content of CHAR_QUEUE
// passed as argument.
// h. Implement DESTROY_CHAR_QUEUE to remove CHAR_QUEUE passed from
// the memory.

#include<stdio.h>
#include<stdlib.h>

struct CHAR_QUEUE{
    char *arr;
    int size,front,rear;

};

struct CHAR_QUEUE* CREATE_CHAR_QUEUE(int size){

struct CHAR_QUEUE *q=(struct CHAR_QUEUE*)malloc(sizeof(struct CHAR_QUEUE));
q->size=size;
q->front=-1;
q->rear=-1;
q->arr=(char*)malloc(size*sizeof(char));
return q;
}

int IS_EMPTY_QUEUE(struct CHAR_QUEUE* q){
    if(q->front==-1&&q->rear==-1){
        printf("queue is empty\n");
        return 1;
    }return 0;
}
int IS_FULL_QUEUE(struct CHAR_QUEUE* q){
    if(q->rear==q->size-1){
        printf("queue is full\n");
        return 1;
    }return 0;
}

void ENQUEUE_CHAR_QUEUE(struct CHAR_QUEUE* q,char x){
if(IS_FULL_QUEUE(q)){
        printf("queue is full....\n");
        return;
        }
        else if(q->front==-1&&q->rear==-1){
            q->front=q->rear=0;
            q->arr[q->rear]=x;
        }else{
           q->rear++;
            q->arr[q->rear]=x;

        }
}

void DEQUEUE_CHAR_QUEUE(struct CHAR_QUEUE* q){
    if(IS_EMPTY_QUEUE(q)){
        printf("queue is empty:");
        return;
    }
    else if(q->front==q->rear){
        q->front=q->rear=-1;
    }else{
        printf("\ndequeue element:");
        printf("%c\n",q->arr[q->front]);
        q->front++;
    }
}

void FRONT_CHAR_QUEUE(struct CHAR_QUEUE* q){
    if(IS_EMPTY_QUEUE(q)){
        printf("queue is empty:");
        return;
    }else{
        printf("\ntop element:\n");
        printf("%c\n",q->arr[q->front]);
    }}
void DISPLAY_CHAR_QUEUE(struct CHAR_QUEUE* q){
     if(IS_EMPTY_QaUEUE(q)){
        printf("queue is empty:");
        return;
    }else{
        printf("queue elements:\n");
        for(int i=q->front;i<q->rear+1;i++){
            printf("| %c |",q->arr[i]);
        }
    }
}

void DESTROY_CHAR_QUEUE(struct CHAR_QUEUE* q){
    free(q->arr);
    free(q);
}
