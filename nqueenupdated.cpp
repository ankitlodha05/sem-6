#include <iostream>
#include <vector>

using namespace std;

bool is_safe(vector<vector<int>>& board, int row, int col, int N) {
    // Check the row on the left side
    for (int i = 0; i < col; ++i) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check lower diagonal on left side
    for (int i = row, j = col; i < N && j >= 0; ++i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solve_n_queens(vector<vector<int>>& board, int col, int N) {
    // Base case: If all queens are placed
    if (col >= N) {
        return true;
    }

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; ++i) {
        if (is_safe(board, i, col, N)) {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Recur to place the rest of the queens
            if (solve_n_queens(board, col + 1, N)) {
                return true;
            }

            // If placing queen in board[i][col] doesn't lead to a solution, then remove queen from board[i][col]
            board[i][col] = 0;
        }
    }

    // If the queen can't be placed in any row in this column col, then return false
    return false;
}

void print_solution(vector<vector<int>>& board) {
    int N = board.size();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool n_queens(int N) {
    // Initialize the board
    vector<vector<int>> board(N, vector<int>(N, 0));

    // Call the recursive function to solve the problem
    if (!solve_n_queens(board, 0, N)) {
        cout << "Solution does not exist" << endl;
        return false;
    }

    // Print the solution
    print_solution(board); 
    return true;
}

int main() {
    // Example usage:
    n_queens(3);  // Change the number to solve for different N values
    return 0;
}
