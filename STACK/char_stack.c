
#include <stdio.h>
#include <stdlib.h>
struct CHAR_STACK
{
    int size;
    int top;
    char *arr;
};

struct CHAR_STACK *CREATE_CHAR_STACK(int sz)
{

    struct CHAR_STACK *s = (struct CHAR_STACK *)malloc(sizeof(struct CHAR_STACK *));
    s->top = -1;
    s->size = sz;
    s->arr = (char *)malloc(s->size * sizeof(char));

    return s;
}

int IS_EMPTY_CHAR_STACK(struct CHAR_STACK *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

int IS_FULL_CHAR_STACK(struct CHAR_STACK *s)
{
    if (s->top >= s->size - 1)
    {
        return 1;
    }
    return 0;
}

void PUSH_CHAR_STACK(struct CHAR_STACK *s, char x)
{
    if (IS_FULL_CHAR_STACK(s))
    {
        printf("stack overflow:");
    }
    else
    {
        s->top++;
        s->arr[s->top] = x;
    }
}

char POP_CHAR_STACK(struct CHAR_STACK *s)
{
    if (IS_EMPTY_CHAR_STACK(s))
    {
        printf("stack is empty");
        return -1;
    }
    else
    {
        char x = s->arr[s->top];
        s->top--;
        return x;
    }
}

char PEAK_CHAR_STACK(struct CHAR_STACK *s)
{
    if (IS_EMPTY_CHAR_STACK(s))
    {
        printf(" stack is empty");
        return -1;
    }
    else
    {
        char x = s->arr[s->top];
        return x;
    }
}
void DISPLAY_CHAR_STACK(struct CHAR_STACK *s)
{
    if (IS_EMPTY_CHAR_STACK(s))
    {
        printf("stack is empty");
        return;
    }
    else
    {
        printf("stack elements:\n");
        for (int i = s->top; i >= 0; i--)
        {
            printf("%c", s->arr[i]);
        }
    }
}

void DESTROY_CHAR_STACK(struct CHAR_STACK *s)
{
    free(s->arr);
    free(s);
}

