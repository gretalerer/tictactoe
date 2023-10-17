//
// Created by Greta Lerer on 16/10/23. Sharing on github.
//

#include <stdio.h>
#include "tictactoe.h"

FILE *filePointer; // Declare filePointer as a FILE type variable

char grid[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};


void displayGrid() {
    printf("  1 | 2 | 3\n");
    printf(" -----------\n");
    printf("1 %c | %c | %c\n", grid[0][0], grid[0][1], grid[0][2]);
    printf(" -----------\n");
    printf("2 %c | %c | %c\n", grid[1][0], grid[1][1], grid[1][2]);
    printf(" -----------\n");
    printf("3 %c | %c | %c\n", grid[2][0], grid[2][1], grid[2][2]);
}

int checkWin(char player, char grid[3][3]) {
    // Check horizontal wins
    for (int i = 0; i < 3; ++i) {
        if (grid[i][0] == player && grid[i][1] == player && grid[i][2] == player) {
            return 1; // Horizontal win
        }
    }

    // Check vertical wins
    for (int i = 0; i < 3; ++i) {
        if (grid[0][i] == player && grid[1][i] == player && grid[2][i] == player) {
            return 1; // Vertical win
        }
    }

    // Check diagonal wins
    if ((grid[0][0] == player && grid[1][1] == player && grid[2][2] == player) ||
        (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player)) {
        return 1; // Diagonal win
    }

    return 0; // No win yet
}


int isValidMove(int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && grid[row][col] == ' ') {
        return 1; // Valid move
    }
    return 0; // Invalid move
}

int isDraw() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i][j] == ' ') {
                return 0; // Game is not a draw yet
            }
        }
    }
    return 1; // Game is a draw
}

void saveToFile() {
    FILE *filePointer = fopen("tictactoe.txt", "w");

    fprintf(filePointer, "  1 | 2 | 3\n");
    fprintf(filePointer, " -----------\n");
    fprintf(filePointer, "1 %c | %c | %c\n", grid[0][0], grid[0][1], grid[0][2]);
    fprintf(filePointer, " -----------\n");
    fprintf(filePointer, "2 %c | %c | %c\n", grid[1][0], grid[1][1], grid[1][2]);
    fprintf(filePointer, " -----------\n");
    fprintf(filePointer, "3 %c | %c | %c\n", grid[2][0], grid[2][1], grid[2][2]);

    printf("Game state has been saved to tictactoe.txt.\n");

    fclose(filePointer);

}


int main() {

    char currentPlayer = 'X';
    int row, col;

    while (1) {
        printf("\nCurrent Grid:\n");
        displayGrid();
        printf("Player %c's turn. Enter a row (1-3) and  a column (1-3): ", currentPlayer);
        scanf("%d %d", &row, &col);
        row--;
        col--;

        if (isValidMove(row, col)) {
            grid[row][col] = currentPlayer;

            if (checkWin(currentPlayer, grid)) {
                printf("\nCurrent Grid:\n");
                displayGrid();
                printf("Player %c wins!\n", currentPlayer);
                saveToFile();
                break;
            }

            if (isDraw()) {
                printf("\nCurrent Grid:\n");
                displayGrid();
                printf("The game is a draw!\n");
                saveToFile();
                break;
            }

            displayGrid();
            saveToFile(); //to save the current status of the game

            if (currentPlayer == 'X') {
                currentPlayer = 'O';
            } else {
                currentPlayer = 'X';
            }


        } else {
            printf("Invalid move. Try again.\n");
        }
    }


    return 0;
}

