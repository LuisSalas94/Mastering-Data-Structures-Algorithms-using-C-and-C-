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
        return ((n%10) + fun(n/10));
    }
}


int main()
{

    int n;
    int sum;
    printf("Enter a number: ");
    scanf("%d", &n);

    sum = fun(n);
    printf("Sum of digit is: %d", sum);

    return 0;
}
