#include <stdio.h>
#include <stdlib.h>

int main()
{
    char A[] = "How are you";
    int i, words = 0;

    for(i = 0; A[i] != '\0'; i++)
    {
        if(A[i] == ' ' && A[i-1] != ' ')
        {
            words++;
        }
    }

    printf("Number of words is: %d", words+1);


    return 0;
}
