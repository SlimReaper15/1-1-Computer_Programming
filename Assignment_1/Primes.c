#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        int flag = 0;
        for (int j = 2; j <= (i / 2); j++)
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            printf("%d ", i);
    }
    printf("\n");
}