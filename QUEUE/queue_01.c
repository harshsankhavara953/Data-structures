#include<stdio.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;

void enqueue(int x){
if(rear==N-1){
    printf("queue if full");
}
else if(front==-1&&rear==-1){
    front=rear=0;
    queue[rear]=x;
}else{
    rear++;
    queue[rear]=x;
}}

void dequeue(){
    if(front==-1&&rear==-1){
        printf("queue is empty");}
        else if(front==rear){
            front=rear=-1;
        }else{
            printf("dequeued element from queue is:%d\n",queue[front]);
            front++;
        }
    }


void peek(){
    if(front==-1&&rear==-1){
        printf("queue is empty");}
        else{
            printf("\ntop element of queue is %d\n",queue[front]);
        }
}

void display(){
    if(front==-1&&rear==-1){
        printf("queue is empty");
    }else{
        printf("queue elements:");

        for (int i=front;i<rear+1;i++){
            printf("%d \t",queue[i]);
        }
    }
}

int main(){
enqueue(2);
enqueue(5);
enqueue(-1);
display();

dequeue(-1);
display();
peek();
dequeue();

return 0;
}
