//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to check if placing num at (row, col) is valid
    bool isValid(vector<vector<int>> &mat, int row, int col, int num) {
        // Check row and column
        for (int i = 0; i < 9; i++) {
            if (mat[row][i] == num || mat[i][col] == num)
                return false;
        }

        // Check the 3x3 sub-grid
        int startRow = (row / 3) * 3, startCol = (col / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (mat[startRow + i][startCol + j] == num)
                    return false;
            }
        }
        return true;
    }

    // Recursive backtracking function to solve Sudoku
    bool solve(vector<vector<int>> &mat) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                // Find an empty cell
                if (mat[row][col] == 0) {
                    // Try placing numbers 1-9
                    for (int num = 1; num <= 9; num++) {
                        if (isValid(mat, row, col, num)) {
                            mat[row][col] = num; // Place the number

                            // Recursively solve the rest of the grid
                            if (solve(mat))
                                return true;

                            // Undo (backtrack) if the solution is not valid
                            mat[row][col] = 0;
                        }
                    }
                    return false; // If no number can be placed, return false
                }
            }
        }
        return true; // Solved successfully
    }

    // Wrapper function to solve the Sudoku puzzle
    void solveSudoku(vector<vector<int>> &mat) {
        solve(mat);
    }
};

// Function to print the Sudoku grid
void printGrid(vector<vector<int>> &mat) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}


//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends