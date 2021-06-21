#include <stdio.h>
#include <stdlib.h>

int main()
{
    char A[] = "How are you";
    int i, vcount = 0, ccount;

    for(i = 0; A[i] != '\0'; i++)
    {
        if(A[i] == 'a' || A[i] == 'e'
           || A[i] == 'i' || A[i] == 'o'
           || A[i] == 'u' || A[i] == 'A'
           || A[i] == 'E' || A[i] == 'I'
           || A[i] == 'O' || A[i] == 'U' )
        {
                vcount++;
        }
        else if((A[i]>=65 && A[i]<=90 || (A[i]>=97 && A[i]<=122)))
        {
            ccount++;
        }
    }

    printf("Number of vowels is: %d\n", vcount);
    printf("Number of consonants is: %d\n", ccount);

    return 0;
}
