#include <stdio.h>
#include <string.h>

int main(void)
{
    int n, k;
    scanf("%d %d", &n, &k);
    char s[n];
    scanf("%s", s);
    int distancefroma[n];
    int maxshift[n];
    int max[n];
    int yes = 0;

    for (int i = 0; i < n; i++)
    {
        distancefroma[i] = s[i] - 'a';
        maxshift[i] = ((122 - s[i]) > (s[i] - 97)) ? (122 - s[i]) : (s[i] - 97);
        yes += maxshift[i];
        if (i == 0)
            max[i] = maxshift[i];
        else
            max[i] = max[i - 1] + maxshift[i];
    }

    if (yes < k)
    {
        printf("-1\n");
        return 0;
    }
    
    int done = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int possible = max[n - 1] - max[i];
        if (distancefroma[i] + possible > k - done && done < k && (k - done) > distancefroma[i])
        {
            s[i] = 'a';
            done += distancefroma[i];
        }
        else if (done < k)
        {
            int whattodo = (k - done - possible) > 0 ? k - done - possible : k - done;
            if (s[i] - whattodo >= 'a' && s[i] - whattodo <= 'z')
                s[i] -= whattodo;
            else
                s[i] += whattodo;
            done += whattodo;
        }
    }

    if (s[n - 1] - (k - done) >= 97 && s[n - 1] - (k - done) <= 122)
        s[n - 1] -= (k - done);
    else
        s[n - 1] += (k - done);
    
    printf("%s\n", s);
}