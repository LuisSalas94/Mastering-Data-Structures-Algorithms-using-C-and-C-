#include <stdio.h>
#include <stdlib.h>

int main()
{

    char A[] = "finding";
    int H[26];

    for(int i = 0; A[i] != '\0'; i++)
    {
        H[A[i]-97]+=1;
    }

    for(int i = 0; i<26; i++)
    {
        if(H[i] > 1)
        {
            printf("%d", i+97);
            printf("%d", H[i]);
        }
    }

    return 0;
}
