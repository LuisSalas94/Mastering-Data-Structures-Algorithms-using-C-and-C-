#include <stdio.h>
#include <stdlib.h>

int main()
{

    char A[] = "python";
    char t;
    int i, j;

    for(j = 0; A[j] != '\0'; j++)
    {

    }
    j--;

    for(i = 0; i<j; i++, j--)
    {
        t = A[i];
        A[i] = A[j];
        A[j] = t;
    }

    printf("%s", A);

    return 0;
}
