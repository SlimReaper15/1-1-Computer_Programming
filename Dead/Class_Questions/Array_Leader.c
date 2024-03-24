#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int lead = a[n - 1], leader[n], count = 1;
    leader[n - 1] = lead;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] > lead)
        {
            lead = a[i];
            count++;
            leader[n - count] = lead;
        }
    }
    for (int i = n - count; i < n; i++)
        printf("%d ", leader[i]);
    printf("\n");
}