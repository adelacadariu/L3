#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *actualstack;
    int maxsize;
    int defaultvalue;
    int top;
} stack;

stack initstack(int stacksize, int defaulvalue);
void push(stack *st, int x);
void pop(stack *st);
int peek(stack *st);
void setvalueintop(stack *st, int newval);
void print(stack *st);
int isempty(stack *st);
int isfull(stack *st);
void showBits(unsigned short a);

stack initstack(int stacksize, int defaultvalue)
{
    stack newstack;
    int i = 0;
    newstack.actualstack = NULL;
    newstack.actualstack = (int*)malloc(stacksize * sizeof(int));
    newstack.defaultvalue = defaultvalue;
    for (i = 0; i < stacksize; ++i)
    {
        newstack.actualstack[i] = defaultvalue;
    }
    newstack.maxsize = stacksize;
    newstack.top = -1;
    return newstack;
}
void push(stack *st, int x)
{
    if(isfull(st)) printf("nope"), exit(EXIT_FAILURE);
    st->top += 1;
    st->actualstack[(st->top)] = x;
}
void pop(stack *st)
{
    if(isempty(st)) exit(EXIT_FAILURE);
    st->actualstack[(st->top)] = st->defaultvalue;
    st->top--;
}
int peek(stack *st)
{
    if(isempty(st)) exit(EXIT_FAILURE);
    return st->actualstack[(st->top)];
}
void setvalueintop(stack *st, int newval)
{
    if(isempty(st)) exit(EXIT_FAILURE);
    st->actualstack[(st->top)] = newval;
}
void print(stack *st)
{
    int i;
    printf("Stack: ");
    for (i = 0; i <= st->top; ++i)
    {
        ///printf("%d ", st->actualstack[i]);
        showBits(st->actualstack[i]);
    }
    ///printf("\n");
}
int isfull(stack *st)
{
    if(st->top >= st->maxsize - 1) return 1;
    return 0;
}
int isempty(stack *st)
{
    if(st->top == -1) return 1;
    return 0;
}
void showBits(unsigned short a)
{
    int i;
    for(i = sizeof(a) * 8 - 1; i >= 0; i--)
    {
        printf("%d", (a >> i) & 1);
        if(i % 4 == 0) printf(" ");
    }
    printf("\n");
}

int main()
{
    int i, n; unsigned short *v; stack s;
    printf("citeste numarul n si apoi n numere naturale: ");
    scanf("%d", &n);
    v = (unsigned short*)malloc(n * sizeof(unsigned short));
    if(v == NULL) exit(EXIT_FAILURE);
    s = initstack(n + 2, -1);
    for (i = 0; i < n; ++i)
    {
        scanf("%u", &v[i]);
        push(&s, ~v[i]);
    }
    print(&s);
    free(s.actualstack);
    free(v);
    return 0;
}
