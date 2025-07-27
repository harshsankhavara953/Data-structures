#include "char_queue.c"
#include<stdio.h>
int main(){
     struct CHAR_QUEUE *queue = CREATE_CHAR_QUEUE(5);
    
    ENQUEUE_CHAR_QUEUE(queue, 'A');
    ENQUEUE_CHAR_QUEUE(queue, 'B');
    ENQUEUE_CHAR_QUEUE(queue, 'C');
    
    DISPLAY_CHAR_QUEUE(queue);
    
    
DEQUEUE_CHAR_QUEUE(queue);
    FRONT_CHAR_QUEUE(queue);

    DISPLAY_CHAR_QUEUE(queue);
    
    DESTROY_CHAR_QUEUE(queue);
    
    return 0;
}