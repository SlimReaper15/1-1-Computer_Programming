#include <stdio.h>
int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    int track = 0, days = 0;
    while (n > 0)
    {
        n--;
        track++;
        if (track % m == 0)
            n++;
        days++;
    }
    printf("%d\n", days);
}