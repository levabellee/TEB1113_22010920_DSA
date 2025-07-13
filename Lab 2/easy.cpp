/* Name: Lez Evabelle Kennedy
Student ID: 22010920
Lab No.: 2
Difficulty: Easy */

// Easy: Find maximum element of each row in a user-input matrix

#include <iostream>
#include <vector>
using namespace std;

// Function to find maximum value entered for each row
vector<int> maxNums(vector<vector<int>>& mat) {
    vector<int> temp;
    
    for(int i=0; i<mat.size(); i++) {
        int maxVal = mat[i][0];
        for(int j=0; j<mat.size(); j++) {
            if (mat[i][j] > maxVal)
                maxVal = mat[i][j];
        }
        temp.push_back(maxVal);
    }
    return temp;
}

int main() {
    // Declare variables rows and columns
    int rows, columns;
    
    // Input number of rows and columns
    cout << "Enter number of rows: "; cin >> rows;
    cout << "Enter number of columns: "; cin >> columns;
    cout << endl;
    
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
    
    // Find maximum value in each row 
    vector<int> temp = maxNums(mat);
    
    // Display the results
    cout << "\nMaximum element in each row:\n";
    for (int i=0; i<temp.size(); i++){
        cout << "Row " << i+1 << ": " << temp[i] << endl;
    }
    
    return 0;
}
