class Solution {
  private:
    const int N = 9;

    bool isSafe(vector<vector<int>> &mat, int row, int col, int num) {
        for (int x = 0; x < N; x++) {
            if (mat[row][x] == num || mat[x][col] == num) {
                return false;
            }
        }

        int startRow = row - row % 3, startCol = col - col % 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (mat[i + startRow][j + startCol] == num) {
                    return false;
                }
            }
        }
        return true;
    }

    bool solve(vector<vector<int>> &mat) {
        int row = -1, col = -1;
        bool isEmpty = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (mat[i][j] == 0) {
                    row = i;
                    col = j;
                    isEmpty = true;
                    break;
                }
            }
            if (isEmpty) break;
        }
        if (!isEmpty) return true;

        for (int num = 1; num <= 9; num++) {
            if (isSafe(mat, row, col, num)) {
                mat[row][col] = num;
                if (solve(mat)) return true;
                mat[row][col] = 0;
            }
        }
        return false;
    }

  public:
    void solveSudoku(vector<vector<int>> &mat) {
        solve(mat);
    }
};
