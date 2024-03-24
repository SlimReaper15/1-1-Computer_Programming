#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int health;
    int index;
}
monster;

int compare (const void *x_void, const void *y_void)
{
    monster x = *((monster *)x_void);
    monster y = *((monster *)y_void);
    if (x.health != y.health)
        return y.health - x.health;
    else
        return x.index - y.index;
}

int main(void)
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        monster grr[n];
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &grr[j].health);
            grr[j].health %= k;
            if (grr[j].health == 0)
                grr[j].health = k;
            grr[j].index = j + 1;
        }
        qsort(grr, n, sizeof(monster), compare);
        for (int j = 0; j < n; j++)
            printf("%d ", grr[j].index);
        printf("\n");
    }
}

// typedef struct monster
// {
//     int index;
//     int health;
// }
// monster;

// int maxele(monster grr[], int n);

// int main(void)
// {
//     int t;
//     scanf("%d", &t);
//     for (int i = 0; i < t; i++)
//     {
//         int n, k;
//         scanf("%d %d", &n, &k);
//         monster grr[n];
//         for (int j = 0; j < n; j++)
//         {
//             scanf("%d", &grr[j].health);
//             grr[j].index = j;
//         }
//         int count = 0, order[n];
//         for (int j = 0; j < n; j++)
//         {
//             int max = maxele(grr, n);
//             while (grr[max].health > 0)
//             {
//                 max = maxele(grr, n);
//                 grr[max].health -= k;
//             }
//             order[count] = grr[max].index;
//             count++;
//         }
//         for (int j = 0; j < n; j++)
//             printf("%d ", order[j] + 1);
//         printf("\n");
//     }
// }

// int maxele(monster grr[], int n)
// {
//     int max = 0;
//     for (int p = 0; p < n; p++)
//     {
//         if (grr[p].health > grr[max].health)
//             max = grr[p].index;
//     }
//     return max;
// }