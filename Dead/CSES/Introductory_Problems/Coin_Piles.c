#include <stdio.h>
int main(void)
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if (((2 * a) - b) % 3 == 0 && ((2 * a) - b) / 3 >= 0 && ((2 * b) - a) % 3 == 0 && ((2 * b) - a) / 3 >= 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
}