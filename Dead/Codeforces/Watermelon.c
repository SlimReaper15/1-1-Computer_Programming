#include <stdio.h>
int main(void)
{
    int w;
    scanf("%d", &w);
    if (w % 2 == 1 || w == 2)
        printf("NO\n");
    else
        printf("YES\n");
}