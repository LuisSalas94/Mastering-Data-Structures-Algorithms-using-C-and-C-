#include <stdio.h>
#include <stdlib.h>

int fun(int n, int len)
{
    if(n == 0)
    {
        return 0;
    }
    else
    {
        return pow((n%10), len) + fun(n/10, len);
    }
}




int main()
{
    int n, result, temp;
    int length = 0;
    printf("Enter a number: ");
    scanf("%d", &n);

    //Create a temp variable
    temp = n;

    //Number of digits
    while(temp != 0)
    {
        length++;
        temp = temp/10;
    }

    result = fun(n, length);
    if(n == result)
    {
        printf("\nNumber is Armstrong");
    }
    else
    {
        printf("\nNumber is not Armstrong");
    }

    return 0;
}
