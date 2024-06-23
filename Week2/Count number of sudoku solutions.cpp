#include <bits/stdc++.h>
using namespace std;

const int N = 9;
const int EmptyCell = 0;

int solutions = 0;

bool isValid(vector<vector<int>>& board, int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

void solveSudoku(vector<vector<int>>& board) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (board[row][col] == EmptyCell) {
                for (int num = 1; num <= N; num++) {
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num;
                        solveSudoku(board);
                        board[row][col] = EmptyCell;
                    }
                }
                return;
            }
        }
    }
    solutions++;
}

int main() {
    vector<vector<int>> board(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    solveSudoku(board);

    cout << solutions << endl;

    return 0;
}
