#include <stdio.h>
#include <stdlib.h>

int fun(int n)
{
    if(n == 0)
    {
        return 0;
    }
    else
    {
        return n + fun(n-1);
    }
}


int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("%d", fun(n));

    return 0;
}
