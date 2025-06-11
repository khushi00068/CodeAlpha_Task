#include <iostream>
#include <iomanip>
using namespace std;

const int N = 9;

// Function to print a pretty Sudoku grid
void printBoard(int board[N][N]) {
    cout << "\n+-------+-------+-------+\n";
    for (int row = 0; row < N; row++) {
        cout << "| ";
        for (int col = 0; col < N; col++) {
            if (board[row][col] == 0)
                cout << ". ";
            else
                cout << board[row][col] << " ";
            if ((col + 1) % 3 == 0)
                cout << "| ";
        }
        cout << endl;
        if ((row + 1) % 3 == 0)
            cout << "+-------+-------+-------+\n";
    }
}

// Check if num can be placed at board[row][col]
bool isSafe(int board[N][N], int row, int col, int num) {
    // Check row and column
    for (int x = 0; x < N; x++)
        if (board[row][x] == num || board[x][col] == num)
            return false;

    // Check 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[startRow + i][startCol + j] == num)
                return false;

    return true;
}

// Solve Sudoku using backtracking
bool solveSudoku(int board[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isSafe(board, row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku(board))
                            return true;
                        board[row][col] = 0; // backtrack
                    }
                }
                return false;
            }
        }
    }
    return true; // completed
}

// Main function
int main() {
    int board[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},

        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},

        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "🧩 Initial Sudoku Puzzle:\n";
    printBoard(board);

    if (solveSudoku(board)) {
        cout << "\n✅ Sudoku Solved Successfully!\n";
        printBoard(board);
    } else {
        cout << "\n❌ No solution exists for the given puzzle.\n";
    }

    return 0;
}
