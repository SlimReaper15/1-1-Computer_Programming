#include <stdio.h>

int calcirr(int n, int x[], int a, int irrstore[]);

int main(void)
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        int x[n];
        for (int j = 0; j < n; j++)
            scanf("%d", &x[j]);
        int max = 0;     
        int irrstore[n]; // Storing the irritation sum from each house till n in the calcirr() function
        for (int j = 0; j < n; j++)
            irrstore[j] = 0;
        for (int j = 0; j < n; j++)
        {
            int irr = calcirr(n, x, j, irrstore);
            if (irr > max)
                max = irr;
        }
        printf("%d\n", max);
    }
}

// Recursion
// You could not live with your own failure. Where did that bring you? Back to me

int calcirr(int n, int x[], int a, int irrstore[])
{
    // n = No. of friends, a = House number
    if (a < 0 || a >= n)
        return 0;
    if (irrstore[a] != 0)
        return irrstore[a];
    else
    {
        irrstore[a] = x[a] + calcirr(n, x, a + x[a], irrstore);
        return irrstore[a];
    }
}