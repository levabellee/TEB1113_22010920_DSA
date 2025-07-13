/* Name: Lez Evabelle Kennedy
Student ID: 22010920
Lab No.: 2
Difficulty: Hard*/

// Hard: Boolean Matrix Transformation

#include <iostream>
#include <vector>
using namespace std;

void booleanMatrix(vector<vector<int>>& mat) {
    int col0 = 0, rows = mat.size(),
        cols = mat[0].size();

    // Mark the first row and column if there is a 1 in the matrix
    for (int i = 0; i < rows; i++) {
      
      // Check if 0th column contains 1
        if (mat[i][0] == 1) col0 = 1; 
        for (int j = 1; j < cols; j++) {
            if (mat[i][j] == 1) {
                mat[i][0] = 1;  
                mat[0][j] = 1;  
            }
        }
    }

    // Traverse the matrix in reverse direction and update values
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 1; j--) {
            if (mat[i][0] == 1 || mat[0][j] == 1) {
                mat[i][j] = 1;
            }
        }
        if (col0 == 1) {
            mat[i][0] = 1;
        }
    }
}

int main() {
     // Declare variables
    int rows, columns, ones;
    
    // Input number of rows and columns
    cout << "Enter number of rows: "; cin >> rows;
    cout << "Enter number of columns: "; cin >> columns;
    
    // Declare matrix variable after user determine values
    vector<vector<int>> arr(rows, vector<int>(columns, 0));
    
    // Ask how many 1s to enter
    cout << "How many 1s would you like to insert?: "; cin >> ones;
    cout << endl; 
    
    // Input specific positions to insert 1s
     for (int i=0; i<ones; i++) {
        int r, c;
        cout << "Enter position of 1 #" << i + 1 << " (row and column): ";
        cin >> r >> c;

        // Make sure the index is valid
        if (r >= 1 && r <= rows && c >= 1 && c <= columns) {
            arr[r-1][c-1] = 1; // adjust for 0-based index
        } else {
            cout << "Invalid position. Skipping.\n";
        }
    }
    
    // Display matrix
    cout << "\nMatrix entered:\n";
    for (int x=0; x<rows; x++) {
        for (int y=0; y<columns; y++) {
            cout << arr[x][y] << " ";
        }
        cout << endl;
    }
    
    // Call booleanMatrix function
    booleanMatrix(arr);

    // Display matrix
    cout << "\nBoolean Matrix Table:\n";
    for (int i=0; i<arr.size(); i++) {
        for (int j=0; j<arr[0].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
