#include <stdio.h>
#include <string.h>
#include "char_stack.c"
#include "int_stack.c"
int main()
{
    char str[20];
    printf("enter a string:\n");
    scanf("%s", str);
    int len = strlen(str);
    struct CHAR_STACK *stack = CREATE_STACK(len);

    for (int i = 0; i < len; i++)
    {
        PUSH_CHAR_STACK(stack, str[i]);
    }
    for (int i = 0; i < len; i++)
    {
        str[i] = POP_CHAR_STACK(stack);
    }
    DESTROY_CHAR_STACK(stack);
    printf("reversed string is:%s\n", str);

    return 0;}
    // struct CHAR_STACK *stack = CREATE_STACK(4);

    // PUSH_CHAR_STACK(stack, 'A');
    // PUSH_CHAR_STACK(stack, 'B');

    // PUSH_CHAR_STACK(stack, 'C');
    // PUSH_CHAR_STACK(stack, 'D');
    // DISPLAY_CHAR_STACK(stack);

    // printf("Popped: %c\n", POP_CHAR_STACK(stack));
    // printf("Top element: %c\n", PEAK_CHAR_STACK(stack));
    // struct CHAR_STACK *stack = CREATE_STACK(4);

    // DESTROY_int_STACK(stack);

    // int main()
    // {
    //     struct int_STACK *stack = CREATE_STACK(4);
    //     PUSH_int_STACK(stack, 1);
    //     PUSH_int_STACK(stack, 2);
    //     PUSH_int_STACK(stack, 3);
    //     PUSH_int_STACK(stack, 45);
        
    //     DISPLAY_int_STACK(stack);
    
    //     printf("Popped: %d\n", POP_int_STACK(stack));
    //     printf("Top element: %d\n", PEEK_int_STACK(stack));
        
    //     DISPLAY_int_STACK(stack);
    
    //     DESTROY_int_STACK(stack);
    //     return 0;
    // }
       
