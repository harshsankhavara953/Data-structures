
#include <stdio.h>
#include <stdlib.h>

struct int_STACK
{
    int size;
    int top;
    int *arr;
};

struct int_STACK *CREATE_STACK(int sz)
{
    struct int_STACK *s = (struct int_STACK *)malloc(sizeof(struct int_STACK));
    s->top = -1;
    s->size = sz;
    s->arr = (int *)malloc(s->size * sizeof(int));
    return s;
}

int IS_EMPTY_STACK(struct int_STACK *s)
{
    return s->top == -1;
}

int IS_FULL_STACK(struct int_STACK *s)
{
    return s->top >= s->size - 1;
}

void PUSH_int_STACK(struct int_STACK *s, int x)
{
    if (IS_FULL_STACK(s))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        s->arr[++s->top] = x;
    }
}

int POP_int_STACK(struct int_STACK *s)
{
    if (IS_EMPTY_STACK(s))
    {
        printf("Stack is Empty\n");
        return -1;
    }
    return s->arr[s->top--];
}

int PEEK_int_STACK(struct int_STACK *s)
{
    if (IS_EMPTY_STACK(s))
    {
        printf("Stack is Empty\n");
        return -1;
    }
    return s->arr[s->top];
}

void DISPLAY_int_STACK(struct int_STACK *s)
{
    if (IS_EMPTY_STACK(s))
    {
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d\t", s->arr[i]);
    }
    printf("\n");
}

void DESTROY_int_STACK(struct int_STACK *s)
{
    free(s->arr);
    free(s);
}

int main()
{
    struct int_STACK *stack = CREATE_STACK(4);
    PUSH_int_STACK(stack, 1);
    PUSH_int_STACK(stack, 2);
    PUSH_int_STACK(stack, 3);
    PUSH_int_STACK(stack, 45);

    DISPLAY_int_STACK(stack);

    printf("Popped: %d\n", POP_int_STACK(stack));
    printf("Top element: %d\n", PEEK_int_STACK(stack));

    DISPLAY_int_STACK(stack);

    DESTROY_int_STACK(stack);
    return 0;
}

