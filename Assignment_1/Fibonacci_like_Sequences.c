#include <stdio.h>
int main(void)
{
    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);
    if (n == 1)
        printf("%d ", x);
    else
        printf("%d %d ", x, y);
    for (int i = 0; i < n - 2; i++)
    {
        int temp = x + y;
        printf("%d ", temp);
        x = y;
        y = temp;
    }
}