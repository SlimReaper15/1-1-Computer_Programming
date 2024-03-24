#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int count = 0;
    for (int i = 5; i <= n; i += 5)
    {
        int j = i;
        while (j % 5 == 0 && j > 0)
        {
            count++;
            j /= 5;
        }
    }
    printf("%d\n", count);
}