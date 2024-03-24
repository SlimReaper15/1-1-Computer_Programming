#include <stdio.h>
int main(void)
{
    int n, probs = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int sure, count = 0;
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &sure);
            if (sure)
                count++;
        }
        if (count >= 2)
            probs++;
    }
    printf("%d\n", probs);
}