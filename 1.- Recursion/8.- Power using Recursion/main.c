#include <stdio.h>
#include <stdlib.h>

{
    if(n == 0)
    {
        return 1;
    }
    return power(m, n-1)*m;
}

//Another method
int power1(int m, int n)
{
    if(n == 0)
    {
        return 1;
    }
    if(n%2 == 0)
    {
        return power1(m*m, n/2);
    }
    return m * power1(m*m, (n-1)/2);

}

int main()
{
      int r = power1(3,4);
    printf("%d ", r);
    return 0;
}
