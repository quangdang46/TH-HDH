#include<stdio.h>
int fac_n(int n)
{
    int fac=1,i;
    for(i=1;i<=n;i++)
    {
        fac*=i;
    }
    return fac;
}


