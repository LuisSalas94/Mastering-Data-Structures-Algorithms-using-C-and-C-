#include <stdio.h>
#include <stdlib.h>

int main()
{
    //from uppercase ti lowercase
    /*char A[] = "WELCOME";
    int i;

    for(i = 0; A[i] != '\0'; i++)
    {
        A[i] = A[i] + 32;
    }

    printf("%s", A);
    */

    //toggle cases
    char A[] = "wELCome";
    int i;

    for(i = 0; A[i] != '\0'; i++)
    {
        if(A[i]>=65 && A[i]<=90)
        {
            A[i]+=32;
        }
        else if(A[i]>=97 && A[i]<=122)
        {
            A[i]-=32;
        }
    }
    printf("%s", A);

    return 0;
}
