#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int a, rec = 0, task = 0;;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        if (a > 0)
            rec += a;
        else
        {
            if (rec > 0)
                rec--;
            else
                task++;
        }
    }
    printf("%d\n", task);
}