#include <stdio.h>
#include <string.h>
int main(void)
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        char s[50], c;
        scanf("%s\n", s);
        scanf("%c", &c);
        int l = strlen(s);
        int flag = 0;
        for (int j = 0; j < l; j++)
        {
            if (s[j] == c && j % 2 == 0)
                flag = 1;
        }
        if (flag == 0)
            printf("NO\n");
        else
            printf("YES\n");
    }
}