#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    char s[n + 1];
    scanf("%s", s);
    int track = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ',')
        {
            if (track % 2 == 0)
                s[i] = '*';
        }
        else if (s[i] == '"')
            track++;
    }
    printf("%s\n", s);
}