#include <stdio.h>
#include <string.h>
int check(char x[])
{
    int i;
    for (i = 0; i < strlen(x); i++)
    {
        if ((x[i] >= 97 && x[i] <= 122) || (x[i] >= 65 && x[i] <= 90))
        {
            return 0;
        }
    }
    return 1;
}
//quick sort int array
void quickSort(int arr[], int left, int right)
{
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];
    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

void xuat(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(int argc, char **argv)
{
    int arr[10];
    int i,j=0;
    for (i = 1; i < argc; i++)
    {
        if (check(argv[i]) == 1)
        {
            arr[j++]=atoi(argv[i]);
        }
    }
    quickSort(arr, 0, j - 1);
    printf("Day tang la: ");
    xuat(arr,j);
    return 0;
}
