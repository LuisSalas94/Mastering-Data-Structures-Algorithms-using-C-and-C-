#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fun(int n)
{
    if(n == 0)
    {
        return 0;
    }
    else
    {
        int powResult = pow(n,2);
        printf("%d\n", powResult);
        return fun(n-1);
    }
}


int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    fun(n);
    return 0;
}
