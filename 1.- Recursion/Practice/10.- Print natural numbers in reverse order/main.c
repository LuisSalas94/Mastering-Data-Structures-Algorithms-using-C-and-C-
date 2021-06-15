#include <stdio.h>
#include <stdlib.h>

void fun(int n)
{
    if(n == 0)
    {
        return;
    }
    else
    {
        printf("%d", n);
        return fun(n-1);
    }
}

int main()
{
    int n;
    int result;
    printf("Enter a number: ");
    scanf("%d", &n);
    fun(n);

    return 0;
}
