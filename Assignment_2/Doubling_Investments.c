#include <stdio.h>
int main(void)
{
    int z, invest = 0;
    scanf("%d", &z);
    while (z > 0)
    {
        if (z % 2 == 0)
            z /= 2;
        else
        {
            z /= 2;
            invest++;
        }
    }
    printf("%d\n", invest);
}