#include <stdio.h>
#include <stdlib.h>

int n, m;
char **s;

int find(int column, char c)
{
    for (int i = column; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s[j][i] == c)
                return i;
        }
    }
    return -1;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &n, &m);
        s = (char **)malloc(n * sizeof(char *));
        for (int j = 0; j < n; j++)
            s[j] = (char *)malloc(m * sizeof(char));
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
                scanf(" %c", &s[j][k]);
        }
        char tbf[4] = {'v', 'i', 'k', 'a'};
        int found[4];
        int column = 0;
        for (int j = 0; j < 4; j++)
        {
            found[j] = find(column, tbf[j]);
            column = found[j] + 1;
        }
        if (found[0] == -1 || found[1] == -1 || found[2] == -1 || found[3] == -1)
            printf("NO\n");
        else if (found[0] < found[1] && found[1] < found[2] && found[2] < found[3])
            printf("YES\n");
        else
            printf("NO\n");
    }
}