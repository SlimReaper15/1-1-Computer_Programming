#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int a[n], cross[n], count = 0;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int temp = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > temp)
        {
            temp = a[i];
            cross[count] = a[i];
            count++;
        }
    }
    printf("%d\n%d ", 1 + count, a[0]);
    for (int i = 0; i < count; i++)
        printf("%d ", cross[i]);
}