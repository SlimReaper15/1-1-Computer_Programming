#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Invalid Input\n");
        return 0;
    }

    FILE *ptr;
    ptr = fopen(argv[1], "r");
    if (ptr == NULL)
    {
        printf("Couldn't read file\n");
        return 0;
    }
    
    printf("File read. Processing...\n");

    char ch;
    int c = 0, w = 1, l = 1, p = 1, flag = 0; // w, l, p = 1 since first word, line, para automatically start
    while ((ch = fgetc(ptr)) != EOF)
    {
        c++;
        if (ch == ' ')
        {
            w++;
            flag = 0;
        }
        else if (ch == '\n')
        {
            l++;
            flag++;
            if (flag == 2)
                p++;
            else if (flag == 1)
                w++;
        }
        else
            flag = 0;
    }
    printf("%d %d %d %d\n", c, w, l, p);
}