#include <stdio.h>
int main(void)
{
    char c;
    int up = 0, low = 0, flag = 0;
    int track[128];
    for (int i = 0; i < 128; i++)
        track[i] = 0;
    while (scanf("%c", &c) == 1 && c != '\n')
    {
        int asc = (int)c;
        if (asc >= 65 && asc <= 90)
            up = 1;
        else if (asc >= 97 && asc <= 122)
            low = 1;
        track[asc]++;
        if (track[asc] > 1)
        {
            flag = 1;
            break;
        }
    }
    if (up > 0 && low > 0 && flag == 0)
        printf("Yes\n");
    else
        printf("No\n");
}