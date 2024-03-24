#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

int main(void)
{
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        char command[20];
        scanf("%s", command);

        int flag = 0;
        int d;

        if (strcmp(command, "history") == 0)
            flag = 1;
        else
            scanf("%d", &d);

        FILE *his = fopen("mx_history", "a");
        fprintf(his, "LOG::%s", command);

        if (flag == 0)
            fprintf(his, " %d\n", d);
        else
            fprintf(his, "\n");
            
        fclose(his);
        
        if (strcmp(command, "history") == 0)
        {
            FILE *r = fopen("mx_history", "r");
            char c;
            while ((c = fgetc(r)) != EOF)
                printf("%c", c);
            fclose(r);
        }
        
        if (strcmp(command, "destroy_matrix") == 0)
        {
            Matrix *a = input();
            destroy_matrix(a);
        }

        else if (strcmp(command, "add_matrix") == 0)
        {
            if (d == 0)
            {
                Matrix *a = input();
                Matrix *b = input();
                Matrix *res = add_matrix(a, b);
                if (res == NULL)
                    printf("ERROR: INVALID ARGUMENT\n");
                else
                    print_matrix(res);

                destroy_matrix(a);
                destroy_matrix(b);
                if (res != NULL)
                    destroy_matrix(res);
            }
            else
            {
                char x[100], y[100], z[100];
                scanf("%s %s %s", x, y, z);
                Matrix *a = read_matrix_from_file(x);
                Matrix *b = read_matrix_from_file(y);
                if (a == NULL || b == NULL)
                {
                    printf("ERROR: INVALID ARGUMENT\n");
                    continue;
                }
                Matrix *res = add_matrix(a, b);
                if (res != NULL)
                    write_matrix_to_file(z, res);
                else
                    printf("ERROR: INVALID ARGUMENT\n");

                destroy_matrix(a);
                destroy_matrix(b);
                if (res != NULL)
                    destroy_matrix(res);
            }
        }

        else if (strcmp(command, "mult_matrix") == 0)
        {
            if (d == 0)
            {
                Matrix *a = input();
                Matrix *b = input();
                Matrix *res = mult_matrix(a, b);
                if (res == NULL)
                    printf("ERROR: INVALID ARGUMENT\n");
                else
                    print_matrix(res);

                destroy_matrix(a);
                destroy_matrix(b);
                if (res != NULL)
                    destroy_matrix(res);
            }
            else
            {
                char x[100], y[100], z[100];
                scanf("%s %s %s", x, y, z);
                Matrix *a = read_matrix_from_file(x);
                Matrix *b = read_matrix_from_file(y);
                if (a == NULL || b == NULL)
                {
                    printf("ERROR: INVALID ARGUMENT\n");
                    continue;
                }
                Matrix *res = mult_matrix(a, b);
                if (res != NULL)
                    write_matrix_to_file(z, res);
                else
                    printf("ERROR: INVALID ARGUMENT\n");

                destroy_matrix(a);
                destroy_matrix(b);
                if (res != NULL)
                    destroy_matrix(res);
            }
        }

        else if (strcmp(command, "scalar_mult_matrix") == 0) 
        {
            if (d == 0)
            {
                long long int s;
                scanf("%lld", &s);
                Matrix *a = input();
                if (a == NULL)
                {
                    printf("ERROR: INVALID ARGUMENT\n");
                    continue;
                }
                Matrix *res = scalar_mult_matrix(s, a);
                if (res != NULL)
                    print_matrix(res);
                else
                    printf("ERROR: INVALID ARGUMENT\n");

                destroy_matrix(a);
                if (res != NULL)
                    destroy_matrix(res);
            }
            else
            {
                long long int s;
                scanf("%lld", &s);
                char x[100], y[100];
                scanf("%s %s", x, y);
                Matrix *a = read_matrix_from_file(x);
                if (a == NULL)
                {
                    printf("ERROR: INVALID ARGUMENT\n");
                    continue;
                }
                Matrix *res = scalar_mult_matrix(s, a);
                if (res != NULL)
                    write_matrix_to_file(y, res);
                else
                    printf("ERROR: INVALID ARGUMENT\n");

                destroy_matrix(a);
                if (res != NULL)
                    destroy_matrix(res);
            }
        }

        else if (strcmp(command, "transpose_matrix") == 0) 
        {
            if (d == 0)
            {
                Matrix *a = input();
                Matrix *res = transpose_matrix(a);
                print_matrix(res);

                destroy_matrix(a);
                if (res != NULL)
                    destroy_matrix(res);
            }
            else
            {
                char x[100], y[100];
                scanf("%s %s", x, y);
                Matrix *a = read_matrix_from_file(x);
                if (a == NULL)
                {
                    printf("ERROR: INVALID ARGUMENT\n");
                    continue;
                }
                Matrix *res = transpose_matrix(a);
                if (res != NULL)
                    write_matrix_to_file(y, res);
                else
                    printf("ERROR: INVALID ARGUMENT\n");

                destroy_matrix(a);
                if (res != NULL)
                    destroy_matrix(res);
            }
        }

        else if (strcmp(command, "determinant") == 0) 
        {
            if (d == 0)
            {
                Matrix *a = input();
                long long int det = determinant(a);
                if (det == -1)
                    printf("ERROR: INVALID ARGUMENT\n");
                else
                    printf("%lld\n", det);

                destroy_matrix(a);
            }
            else
            {
                char x[100];
                scanf("%s", x);
                Matrix *a = read_matrix_from_file(x);
                if (a == NULL)
                {
                    printf("ERROR: INVALID ARGUMENT\n");
                    continue;
                }
                long long int det = determinant(a);
                if (det == -1)
                    printf("ERROR: INVALID ARGUMENT\n");
                else
                    printf("%lld\n", det);

                destroy_matrix(a);
            }
        }
    }
}