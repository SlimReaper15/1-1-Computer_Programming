#include <stdio.h>
int main(void)
{
    int dd, mm, yy;
    scanf("%d-%d-%d", &dd, &mm, &yy);
    printf("%02d-%02d-%02d\n", mm, dd, yy);
}