#include <stdio.h>
int main(void)
{
    int w, h;
    scanf("%d %d", &w, &h);
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if ((i == 1 || i == h) && (j == 1 || j == w))
                printf("o");
            else if ((i == 1 || i == h) && (j != 1 && j != w))
                printf("-");
            else if ((i != 1 && i != h) && (j == 1 || j == w))
                printf("|");
            else
                printf(" ");
            if (j == w)
                printf("\n");
        }
    }
}