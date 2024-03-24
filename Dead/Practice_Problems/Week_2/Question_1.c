#include <math.h>
#include <stdio.h>
int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);
    // First condition checks whether the elements are in the same row
    // We do a - 1 cuz we want 0, 1 and 2 as the column indices to check whether the elements are adjacent. 1, 2 and 0 will cause 1 and 3 to be adjacent 
    if (ceil(a / 3.0) == ceil(b / 3.0) && abs(((a - 1) % 3) - ((b - 1) % 3)) == 1)
        printf("YES\n");
    else
        printf("NO\n");
}