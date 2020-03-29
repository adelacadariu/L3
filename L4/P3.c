#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void sort(int* a, int n)
{
    int i, temp, j;
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            if ((*a + j) == (*a + j + 1))
            {
                temp = *a + j;
                *a + j = *a + j + 1;
                *a + j + 1 = temp;
            }
        }
    }
}
void main()
{
    int a[20];
    int n, i;
    clrscr();

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);


    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    sort(&a, n);
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    getch();
}
