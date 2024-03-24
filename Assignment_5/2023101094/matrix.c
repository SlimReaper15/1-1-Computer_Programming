#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Matrix
{
    int num_rows;
    int num_cols;
    long long int** data;
} Matrix;

Matrix *create_matrix(int r, int c)
{
    Matrix *m = (Matrix *)malloc(sizeof(Matrix));
    m -> num_rows = r;
    m -> num_cols = c;
    m -> data = (long long int **)calloc(r, sizeof(long long int *));
    for (int i = 0; i < r; i++)
        m -> data[i] = (long long int *)calloc(c, sizeof(long long int));
    return m;
}

void destroy_matrix(Matrix *m)
{
    // 1: Write code here to free all memory used by the matrix stored in m

    int r = m -> num_rows;
    int c = m -> num_cols;

    // Freeing the allocated memory inside the struct
    for (int i = 0; i < r; i++)
        free(m -> data[i]);
    free(m -> data);

    // Free the struct
    free(m);
}

Matrix *add_matrix(Matrix *A, Matrix  *B)
{
    // 2: write code here to add the matrices A and B and return a new matrix with the results.
    // A, B should remain unmodified. If dimensions don't match, it should return NULL.

    // Checking for matching dimensions
    if (A -> num_rows != B -> num_rows || A -> num_cols != B -> num_cols)
        return NULL;
    
    // A -> data and B -> data is basically a 2-D array storing the elements
    int r = A -> num_rows;
    int c = A -> num_cols;

    Matrix *sum = create_matrix(r, c);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            sum -> data[i][j] = A -> data[i][j] + B -> data[i][j];
    }

    return sum;
}

Matrix *mult_matrix(Matrix *A, Matrix *B)
{
    // 3: write code here to multiply the matrices A and B and return a new matrix with the results.
    // A, B should remain unmodified. If the dimensions don't match, it should return NULL.

    int r1 = A -> num_rows;
    int c1 = A -> num_cols;

    int r2 = B -> num_rows;
    int c2 = B -> num_cols;

    if (c1 != r2)
        return NULL; // Can't multiply them

    Matrix *prod = create_matrix(r1, c2);

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            long long int sum = 0;
            for (int k = 0; k < c1; k++)
                sum += (A -> data[i][k] * B -> data[k][j]);
            prod -> data[i][j] = sum;
        }
    }
    
    return prod;
}

Matrix *scalar_mult_matrix(long long int s, Matrix *M)
{
    // 4: write code here to multiply the matrix A with a scalar s and return a new matrix with the results.
    // M should remain unmodified.
    int r = M -> num_rows;
    int c = M -> num_cols;

    Matrix *res = create_matrix(r, c);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            res -> data[i][j] = s * M -> data[i][j];
    }

    return res;
}

Matrix *transpose_matrix(Matrix* A) 
{
    // 5: write code here to find the transpose of given matrix A and return a new matrix with the results.
    // A should remain unmodified.

    int r = A -> num_rows;
    int c = A -> num_cols;

    // Have to be careful since dimensions can change while taking transpose

    Matrix *transpose = create_matrix(c, r);

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
            transpose -> data[i][j] = A -> data[j][i]; // Definition of transpose
    }

    return transpose;
}

long long int determinant(Matrix *M)
{
    // 6: Write code here to calculate the determinant of the given matrix M (if not a square matrix, return -1).
    // Return the determinant value.
    
    int r = M -> num_rows;
    int c = M -> num_cols;

    if (r != c)
        return -1;
    else if (r == 1)
        return M -> data[0][0];
    else if (r == 2)
        return (M -> data[0][0] * M -> data[1][1] - M -> data[0][1] * M -> data[1][0]);
    long long int det = 0;
    for (int i = 0; i < c; i++)
    {
        long long int co = pow(-1, i) * M -> data[0][i];
        Matrix *now = create_matrix(r - 1, c - 1);
        int cr = 0, cc = 0; // Keeping track of where I am in the submatrix
        for (int j = 1; j < r; j++)
        {
            for (int k = 0; k < c; k++)
            {
                if (k != i)
                {
                    now -> data[cr][cc] = M -> data[j][k];
                    cc++;
                }
            }
            cr++;
            cc = 0;
        }
        det += co * determinant(now);
    }
    return det;
}

// DO NOT MODIFY THE OUTPUT FORMAT of this function. Will be used for grading
void print_matrix(Matrix *m)
{
    printf("%d %d\n", m -> num_rows, m -> num_cols);
    for (int i = 0; i < m -> num_rows; i++)
    {
        for (int j = 0; j < m -> num_cols; j++)
            printf("%lld ", m -> data[i][j]);
        printf("\n");
    }
}

Matrix *input(void)
{
    int r, c;
    scanf("%d %d", &r, &c);
    Matrix *a = create_matrix(r, c);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int x;
            scanf("%d", &x);
            a -> data[i][j] = x;
        }
    }
    return a;
}

Matrix *read_matrix_from_file(char *name)
{
    FILE *ptr = fopen(name, "r");

    if (ptr == NULL)
        return NULL;

    int rows, cols;

    // Read dimensions from the first line
    fscanf(ptr, "%d %d", &rows, &cols);

    Matrix *read = create_matrix(rows, cols);

    // Read matrix elements
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            fscanf(ptr, "%lld", &(read -> data[i][j]));
    }

    fclose(ptr);
    
    return read;
}

void write_matrix_to_file(char *name, Matrix *m)
{
    FILE *ptr = fopen(name, "w");

    if (ptr == NULL)
        return;

    fprintf(ptr, "%d %d\n", m -> num_rows, m -> num_cols);
    for (int i = 0; i < m -> num_rows; i++)
    {
        for (int j = 0; j < m -> num_cols; j++)
            fprintf(ptr, "%d ", m -> data[i][j]);
        fprintf(ptr, "\n");
    }

    fclose(ptr);
}