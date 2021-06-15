#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p, *q;
    p = (int*)malloc(5*sizeof(int));
    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;

    //create another array of larger size
    q = (int*)malloc(10*sizeof(int));

    //transfer values from p to q
    for(int i = 0; i<5; i++)
    {
        q[i] = p[i];
    }

    //delete p
    free(p);

    //p points to q
    p = q;

    //make q as null
    q = NULL;

    for(int i = 0; i<5; i++)
    {
        printf("%d\n", p[i]);
    }

    return 0;
}
