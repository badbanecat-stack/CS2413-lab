#include <stdio.h>
#include <stdlib.h>

void dfs(char** grid, int gridSize, int* gridColSize, int i, int j) {
    if (i < 0 || j < 0 || i >= gridSize || j >= gridColSize[i] || grid[i][j] != '1')
        return;

    grid[i][j] = '0';

    dfs(grid, gridSize, gridColSize, i - 1, j);
    dfs(grid, gridSize, gridColSize, i + 1, j);
    dfs(grid, gridSize, gridColSize, i, j - 1);
    dfs(grid, gridSize, gridColSize, i, j + 1);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int count = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, gridSize, gridColSize, i, j);
            }
        }
    }

    return count;
}

int main() {
    int rows = 4, cols = 5;
    char* input[] = {
        "11000",
        "11000",
        "00100",
        "00011"
    };

    char** grid = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        grid[i] = (char*)malloc((cols + 1) * sizeof(char));
        for (int j = 0; j < cols; j++) {
            grid[i][j] = input[i][j];
        }
    }

    int* colSizes = (int*)malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++) {
        colSizes[i] = cols;
    }

    int islands = numIslands(grid, rows, colSizes);
    printf("Number of islands: %d\n", islands);

    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
    free(colSizes);

    return 0;
}
