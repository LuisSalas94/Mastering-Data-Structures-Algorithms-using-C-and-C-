#include <stdio.h>
#include <stdlib.h>

int sum = 0;
int fun(int n)
{
    if(n == 0)
    {
        return 0;
    }
    else
    {
        printf("%d ", n);
        sum = sum + n;
        return fun(n-1);
    }
}


int main()
{
    int n;
    int result;
    printf("Enter a number: ");
    scanf("%d", &n);

    result = fun(n);
    printf("%d", result);
    printf("\nSum of the numbers is: %d", sum);

    return 0;
}
