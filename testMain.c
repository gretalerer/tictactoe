//
// Created by Greta Lerer on 16/10/23. Sharing on github. 
//

#include <CUnit/Basic.h>
#include "tictactoe.h"


//clean up test suite
int init_suite(void);
int clean_suite(void);

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testCheckWin(){
    char board1[3][3] = {
            {'X', 'X', 'X'},
            {'O', '4', 'O'},
            {'O', '8', '9'}
    };
    CU_ASSERT_TRUE(checkWin('X',board1)); //checking if x won horizontally.

    char grid2[3][3] = {{'O', 'O', 'O'},
                        {'X', 'X', 'X'},
                        {'X', 'X', 'X'}
    };

    CU_ASSERT_TRUE(checkWin('O', grid2)).

    // Test vertical win
    char grid3[3][3] = {{'X', 'O', 'O'},
                        {'X', 'X', 'O'},
                        {'X', 'O', 'O'}
    }; //When writing the comments for this function, I also realized that the function is impartial to what is happening in the rest of the grid as long as the conditions for winning are satisfied.

    CU_ASSERT_TRUE(checkWin('X', grid3));

    char grid4[3][3] = {{'O', 'X', 'X'},
                        {'O', 'X', 'X'},
                        {'O', 'X', 'X'}
    };

    CU_ASSERT_TRUE(checkWin('O', grid4));

    // Test diagonal win
    char grid5[3][3] = {{'X', 'O', 'O'},
                        {'O', 'X', 'O'},
                        {'O', 'O', 'X'}
    };
    CU_ASSERT_TRUE(checkWin('X', grid5));

    char grid6[3][3] = {{'O', 'X', 'X'},
                        {'X', 'O', 'X'},
                        {'X', 'X', 'O'}
    };
    CU_ASSERT_TRUE(checkWin('O', grid6));
}


void testIsDraw() {

    // Test a non-draw state
    grid[0][0] = 'X';
    grid[1][1] = 'O';
    grid[2][2] = 'X';
    CU_ASSERT_EQUAL(isDraw(), 0);

    // Test a draw state
    grid[0][0] = 'X';
    grid[0][1] = 'O';
    grid[0][2] = 'X';
    grid[1][0] = 'X';
    grid[1][1] = 'X';
    grid[1][2] = 'O';
    grid[2][0] = 'O';
    grid[2][1] = 'X';
    grid[2][2] = 'O';
    CU_ASSERT_EQUAL(isDraw(), 1);
}

void testOccupiedCell() {
    // Initialize the grid. Here I'm testing if a move is valid. 
    char gridh[3][3] = {{'X', 'O', ' '},
                        {' ', 'X', ' '},
                        {' ', 'O', 'O'}};

    // Check if the result is 0 (invalid move)
    CU_ASSERT_EQUAL(isValidMove(1, 1), 0);
}

void testInvalidMoves() {
    // Attempt to make moves outside the grid and with negative values
    int result1 = isValidMove(-1, 2);
    int result3 = isValidMove(1, -2);

    // Check if all results are 0 (invalid moves)
    CU_ASSERT_EQUAL(result1, 0);
    CU_ASSERT_EQUAL(result3, 0);
}


int main() {

    // Initialize the CUnit test registry
    CU_initialize_registry();

    // Add a suite to the registry
    CU_pSuite suite = CU_add_suite("Suite_1", init_suite, clean_suite);


    // Add the test case to the suite
    CU_add_test(suite, "Test is draw", testIsDraw);
    CU_add_test(suite, "Test for occupied cell", testOccupiedCell);
    CU_add_test(suite, "Test for invalid moves", testInvalidMoves);
    CU_add_test(suite, "Test check win", testCheckWin);


    CU_basic_run_tests();

    CU_cleanup_registry();

    return CU_get_error();

}
