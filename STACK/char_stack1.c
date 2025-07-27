#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
// #define n 10
typedef struct
{
    int top;
    char *name;
    int size;
} CHAR_STACK;

CHAR_STACK *createStack(int n)
{
    CHAR_STACK *s = (CHAR_STACK *)malloc(sizeof(CHAR_STACK));
    s->top = -1;
    s->size = n;
    s->name = (char *)calloc(s->size, sizeof(char));
    return s;
}

int isEmpty(CHAR_STACK *s)
{
    return s->top == -1;
}

int isFull(CHAR_STACK *s)
{
    return s->top >= s->size - 1;
}

void push(CHAR_STACK *s, char el)
{
    if (isFull(s))
    {
        printf("\n stack is full");
        return;
    }
    s->top += 1;
    s->name[s->top] = el;
}

char pop(CHAR_STACK *s)
{
    char x;
    if (isEmpty(s))
    {
        printf("\n stack is empty");
        return '\0';
    }
    x = s->name[s->top];
    s->top -= 1;
    return x;
}

char peak(CHAR_STACK *s)
{
    if (isEmpty(s))
    {
        printf("\n stack is empty");
        return '\0';
    }
    return s->name[s->top];
}

void display(CHAR_STACK *s)
{
    for (int i = s->top; i >= 0; i--)
    {
        printf("%c", s->name[i]);
    }
}
int chechprecedence(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/' || ch == '%')
    {
        return 2;
    }
    else if (ch == '^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}

void stackDestroy(CHAR_STACK *s)
{
    free(s);
    s = NULL;
}

void eval(CHAR_STACK *s)
{
    int num1, num2, ans = 0;
    char *e;
    e = s->name;
    while (*e != '\0')
    {
        if (isdigit(*e))
        {
            push(s, *e);
        }
        else if (*e == '+' || *e == '-' || *e == '*' || *e == '/' || *e == '^' || *e == '%')
        {
            num1 = pop(s) - '0';
            num2 = pop(s) - '0';
            switch (*e)
            {
            case '+':
                ans = num2 + num1;
                break;
            case '-':
                ans = num2 - num1;
                break;
            case '*':
                ans = num2 * num1;
                break;
            case '/':
                ans = num2 / num1;
                break;
            case '%':
                ans = num2 % num1;
                break;
            case '^':
                ans = num2 ^ num1;
                break;
            }
            push(s, ans + '0');
        }
        e++;
    }
    printf("\n ans = %d ", ans);
}

void itop(CHAR_STACK *s)
{
    printf("\n enter infix expression");
    scanf("%s", s->name);
    char postfix[strlen(s->name)];
    char *e;
    e = s->name;
    int index = 0;
    while (*e != '\0')
    {
        if (isalpha(*e))
        {
            postfix[index++] = *e;
        }
        else if (*e == '(')
        {
            push(s, *e);
        }
        else if (*e == ')')
        {
            while ((!isEmpty(s)) && peak(s) != '(')
            {
                postfix[index++] = pop(s);
            }
            pop(s);
        }
        else
        {
            while (!isEmpty(s) && chechprecedence(peak(s)) >= chechprecedence(*e))
            {
                postfix[index++] = pop(s);
            }
            push(s, *e);
        }
        e++;
    }
    while (!isEmpty(s))
    {
        postfix[index++] = pop(s);
    }
    printf("\n infix to postfix %s", postfix);
}

void reverseString(CHAR_STACK *s)
{
    printf("Enter a string: ");
    scanf(" %[^\n]", s->name);
    char *ptr = s->name;

    // Create a buffer to store reversed string
    char reversed[strlen(s->name)];
    char *revPtr = reversed;

    // Push each character onto the stack
    while (*ptr != '\0')
    {
        push(s, *ptr);
        ptr++;
    }

    // Pop characters from the stack to reverse the string
    while (!isEmpty(s))
    {
        *revPtr = pop(s);
        revPtr++;
    }
    *revPtr = '\0';

    printf("Reversed string: %s\n", reversed);
}
