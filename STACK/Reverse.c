// Using the above created libraries, write a C program to reverse the string. Here the user 
// will be asked for a string and using stack operations your code should provide a revered 
// string as output. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CHAR_STACK
{
    int size;
    int top;
    char *arr;
};

struct CHAR_STACK *CREATE_CHAR_STACK(int sz)
{
    struct CHAR_STACK *s = (struct CHAR_STACK *)malloc(sizeof(struct CHAR_STACK));
    s->top = -1;
    s->size = sz;
    s->arr = (char *)malloc(s->size * sizeof(char));
    return s;
}

void PUSH_CHAR_STACK(struct CHAR_STACK *s, char x)
{
    if (s->top >= s->size - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = x;
}

char POP_CHAR_STACK(struct CHAR_STACK *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    return s->arr[s->top--];
}

void DESTROY_CHAR_STACK(struct CHAR_STACK *s)
{
    free(s->arr);
    free(s);
}

int main()
{
    char str[20];
    printf("Enter a string:\n");
    scanf("%s",str);
    

    int len = strlen(str);
    struct CHAR_STACK *stack = CREATE_CHAR_STACK(len);

    for (int i = 0; i < len; i++)
    {
        PUSH_CHAR_STACK(stack, str[i]);
    }
    for (int i = 0; i < len; i++)
    {
        str[i] = POP_CHAR_STACK(stack);
    }

    DESTROY_CHAR_STACK(stack);
    printf("Reversed string is: %s\n", str);

    return 0;
}
