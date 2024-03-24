#include <stdio.h>
int palindrome(int n, int *a);
int main(void)
{
    int n, count = 0;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n - i; j++)
        {
            if (palindrome(j, &a[i]) == 0)
                count++;
        }
    }
    printf("%d\n", n + count);
}
int palindrome(int n, int *a) // n = Size of array - 1
{
    int flag;
    for (int i = 0; i <= n / 2; i++)
    {
        flag = 0;
        if (a[i] != a[n - i])
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        return 0;
    else
        return 1;
}