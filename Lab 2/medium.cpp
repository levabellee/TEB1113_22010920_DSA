/* Name: Lez Evabelle Kennedy
Student ID: 22010920
Lab No.: 2
Difficulty: Medium*/

// Medium: Rotate a matrix by 180 degrees

#include <iostream>
#include <vector>
using namespace std;

void rotateMatrix(vector<vector<int>>& mat) {
    int size = mat.size();
  
    // Create an auxiliary matrix
    vector<vector<int>> result(size, vector<int>(size));
  
    // move mat[i][j] to mat[n-i-1][n-j-1]
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            result[i][j] = mat[size-i-1][size-j-1];
        }
    }
    mat = result;
}

int main() {
    // Declare variables rows and columns
    int rows, columns;
    
    // Input number of rows and columns
    cout << "Enter number of rows (and columns): "; cin >> rows;
    columns = rows;
    
    // Declare matrix variable after user determine values
    vector<vector<int>> mat(rows, vector<int>(columns));
    
    // Input all values for the matrix
    for (int x=0; x<rows; x++) {
        for (int y=0; y<columns; y++) {
            cout << "Enter value for row " << x+1 << ", column " << y+1 << ": "; cin >> mat[x][y];
        }
        cout << endl;
    }
    
    // Display matrix
    cout << "Matrix entered:\n";
    for (int x=0; x<rows; x++) {
        for (int y=0; y<columns; y++) {
            cout << mat[x][y] << " ";
        }
        cout << endl;
    }
    
    // Call function rotateMatrix
    rotateMatrix(mat);
    
    // Display rotated matrix
    cout << "\nRotated matrix:\n";
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
