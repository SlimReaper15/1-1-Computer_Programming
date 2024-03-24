#include <stdio.h>
int main(void)
{
    int n, h;
    scanf("%d %d", &n, &h);
    char s[n + 1];
    scanf("%s", s);

    int hash[26];
    for (int i = 0; i < 26; i++)
        hash[i] = 0;
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = i; j < i + h; j++)
        {
            if (s[j] != s[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            hash[s[i] - 'a']++;
            i += h-1;
        }
    }
    int max = hash[0];
    for (int i = 1; i < 26; i++)
    {
        if (hash[i] > max)
            max = hash[i];
    }
    printf("%d\n", max);
}