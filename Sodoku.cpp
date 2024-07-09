#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    // Check rows
    for (int i = 0; i < 9; ++i) {
        set<char> seen;
        for (int j = 0; j < 9; ++j) {
            char current = board[i][j];
            if (current != '.') {
                if (seen.find(current) != seen.end()) {
                    return false; // Duplicate found in the same row
                }
                seen.insert(current);
            }
        }
    }

    // Check columns
    for (int j = 0; j < 9; ++j) {
        set<char> seen;
        for (int i = 0; i < 9; ++i) {
            char current = board[i][j];
            if (current != '.') {
                if (seen.find(current) != seen.end()) {
                    return false; // Duplicate found in the same column
                }
                seen.insert(current);
            }
        }
    }

    // Check 3x3 sub-grids
    for (int block = 0; block < 9; ++block) {
        set<char> seen;
        for (int i = block % 3 * 3; i < block % 3 * 3 + 3; ++i) {
            for (int j = block % 3 * 3; j < block % 3 * 3 + 3; ++j) {
                char current = board[i][j];
                if (current != '.') {
                    if (seen.find(current) != seen.end()) {
                        return false; // Duplicate found in the same 3x3 sub-grid
                    }
                    seen.insert(current);
                }
            }
        }
    }

    return true;
}

int main() {
    vector<vector<char>> board(9, vector<char>(9));

    // Input the Sudoku board
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> board[i][j];
        }
    }

    // Check if the Sudoku board is valid
    if (isValidSudoku(board)) {
        cout << "TRUE" << endl;
    } else {
        cout << "FALSE" << endl;
    }

    return 0;
}