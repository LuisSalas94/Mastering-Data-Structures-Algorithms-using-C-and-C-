#include <stdio.h>
#include <stdlib.h>

//Recursive
int fact(int n)
{
    if(n == 0)
    {
        return 1;
    }
    return fact(n-1)*n;
}


//Using loop
int Ifact(int n)
{
    int f = 1;
    for(int i = 1; i<=n; i++)
    {
        f = f*i;
    }
    return f;

}

int main()
{
      int r;
    r = Ifact(5);
    printf("Factorial is: %d", r);
    return 0;
}
