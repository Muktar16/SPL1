#include"header.h"


int factorial(int n)
{
    int f;
    for(int i=1;i<=n;i++)
    {
        f*=i;
    }
    return f;
}
