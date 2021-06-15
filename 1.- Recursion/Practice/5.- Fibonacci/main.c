#include <stdio.h>
#include <stdlib.h>

int fun(int n)
{
    if(n == 0)return 0;
    if(n == 1)return 1;

    return fun(n-1)+fun(n-2);
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    for(int i = 0; i<=n; i++)
    {
        int r = fun(i);
        printf("%d ", r);
    }
    return 0;
}
