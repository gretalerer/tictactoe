//
// Created by Greta Lerer on 16/10/23. Sharing on github.
//

#ifndef COMPUTERPROGRAMMINGII_TICTACTOE_H
#define COMPUTERPROGRAMMINGII_TICTACTOE_H
#include <stdbool.h>

void displayGrid();
int checkWin(char player, char grid[3][3]);
int isValidMove(int row, int col);
int isDraw();
void saveToFile();
extern char grid[3][3];

#endif //COMPUTERPROGRAMMINGII_TICTACTOE_H
