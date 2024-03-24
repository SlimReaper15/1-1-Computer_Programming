#include <stdio.h>
int main(void)
{
    int hh, mm, ss;
    scanf("%d:%d:%d", &hh, &mm, &ss);
    printf("%g\n", (hh * 60) + (mm) + (ss / 60.0));
}