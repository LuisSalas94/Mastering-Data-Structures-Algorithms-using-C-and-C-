#include <stdio.h>
#include <stdlib.h>

int sum = 0;
int r;

int fun(int n)
{
    if(n)
    {
       r = n%10;
       sum = sum*10 + r;
       return fun(n/10);
    }
    else
    {
        return sum;
    }
}

int main()
{
    int n, result;
    printf("Enter a number: ");
    scanf("%d", &n);
    result = fun(n);
    printf("%d\n", result);

    //Check if number is palindrome or not
    if(result == n)
    {
        printf("Number is palindrome");
    }
    else
    {
        printf("Number is not palindrome");
    }

    return 0;
}
