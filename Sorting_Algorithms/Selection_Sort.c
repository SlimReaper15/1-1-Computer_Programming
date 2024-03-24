#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; i++)
    {
        int imin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[imin])
                imin = j;
        }
        int temp = a[i];
        a[i] = a[imin];
        a[imin] = temp;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}