#include<stdio.h>
void div_n(int n)
{
    int i;
    printf("Divisors %d = ",n);
    for(i=1;i<=n;i++){
        if(n%i==0){
            printf("%d ",i);
        }
    }
}

