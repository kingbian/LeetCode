#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

/**
 * given a 2D array, we must check if a target exists using O(log(m*n)) algorithm ( Binary search)
 *
 * logic:
 *
 *
 *
 */
/* bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int left = 0;
    int right = m * n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // flatten the 2d array
        int x = mid / n;  // get the quotient which is the row (x) index from mid
        int y = mid % n;  // get the remainder which the column(y) index from mid

        // check if we have target
        if (matrix[x][y] == target) {
            return true;
        } else if (matrix[x][y] > target) {
            right = mid - 1;

        } else {
            left = mid + 1;
        }
    }
    return false;
} */

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    int rowCount = matrix.size();
    int colCount = matrix[0].size();

    int topRow = 0, bottomRow = rowCount - 1;
    int midRow = -1;
    while (topRow <= bottomRow) {
        midRow = topRow + (bottomRow - topRow) / 2;  // get the mid row of the matrix

        if (target > matrix[midRow][colCount - 1]) {
            topRow = midRow + 1;
        } else if (target < matrix[midRow][0]) {
            bottomRow = midRow - 1;
        } else {
            break;
        }
    }

    int left = 0, right = colCount - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (matrix[midRow][mid] == target) {
            return true;
        } else if (matrix[midRow][mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return false;
}
int main(void) {
    vector<vector<int>> matrix{{1, 3, 5, 7, 8}, {10, 11, 16, 20, 21}, {23, 30, 34, 60, 61}};

    int target = 3;
    cout << boolalpha;

    cout << searchMatrix(matrix, target) << endl;
}
