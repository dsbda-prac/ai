#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<int>& board, int row, int col, int n) {
    for (int i = 0; i < row; ++i) {
        int queenCol = board[i];
        if (queenCol == col || abs(queenCol - col) == abs(i - row))
            return false;
    }
    return true;
}

bool solveNQueens(vector<int>& board, int row, int n) {
    if (row == n) {
        // Print the solution
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << (board[i] == j ? "Q " : ". ");
            cout << endl;
        }
        cout << endl;
        return true; // Return true to find only one solution
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col, n)) {
            board[row] = col;
            if (solveNQueens(board, row + 1, n))
                return true;
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Enter value of N: ";
    cin >> n;
    vector<int> board(n);
    if (!solveNQueens(board, 0, n))
        cout << "No solution exists.\n";
    return 0;
}
