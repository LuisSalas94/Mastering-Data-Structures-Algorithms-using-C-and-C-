#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[10] = {2,4,6,8,10};
    int *p;

    p = (int*)malloc(5*sizeof(int));
    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;

    for(int i = 0; i<5; i++)
    {
        printf("%d\n", A[i]);
    }

    printf("\n\n");

    for(int i = 0; i<5; i++)
    {
        printf("%d\n", p[i]);
    }

    return 0;
}
