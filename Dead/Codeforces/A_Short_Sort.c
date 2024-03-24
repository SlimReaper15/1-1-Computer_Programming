#include <stdio.h>
int main(void)
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        char a[4];
        scanf("%s", a);
        if (a[0] == 'a' || a[1] == 'b' || a[2] == 'c')
            printf("YES\n");
        else
            printf("NO\n");
    }
}