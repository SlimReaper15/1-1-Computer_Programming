#include <stdio.h>
#include <string.h>

int c[8];
int d[15]; // r + c
int cd[15]; // r - c + 7
// Elements being -1 indiciate that a queen can be placed there, 1 indicates that it can't

int grid[8][8];

int ways = 0;

void search(int row) {
    if (row == 8) {
        ways++;
        return;
    }

    for (int i = 0; i < 8; i++) {
        if (c[i] == 1 || d[row + i] == 1 || cd[row - i + 7] == 1 || grid[row][i] == 1)
            continue;
        
        c[i] = d[row + i] = cd[row - i + 7] = 1;
        search(row + 1);
        c[i] = d[row + i] = cd[row - i + 7] = -1; // Backtracking
    }
}

int main() {
    memset(c, -1, 8 * sizeof(int));
    memset(d, -1, 15 * sizeof(int));
    memset(cd, -1, 15 * sizeof(int));

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char c;

            do {
                scanf("%c", &c); // Newline character messes with the input otherwise
            } while (c == '\n');

            if (c == '*')
                grid[i][j] = 1;
            else
                grid[i][j] = -1;
        }
    }

    search(0);

    printf("%d\n", ways);
}