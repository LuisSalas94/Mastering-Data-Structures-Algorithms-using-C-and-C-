#include <stdio.h>
#include <stdlib.h>

int fun(int n)
{
    if(n == 1)
    {
        return 1;
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

    printf("Sum is: %d", fun(n));

    return 0;
}
