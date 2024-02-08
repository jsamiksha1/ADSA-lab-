#include <iostream>
#include <vector>
using namespace std;


// Function to print a matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

// Function to add two matrices
void addMatrices(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2) {
    int rows = matrix1.size();
    int cols = matrix1[0].size();

    if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size()) {
        cout << "Error: Matrices must be of the same size to perform addition." << endl;
        return;
    }

    cout << "Sum of matrices:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix1[i][j] + matrix2[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to subtract two matrices
void subtractMatrices(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2) {
    int rows = matrix1.size();
    int cols = matrix1[0].size();

    if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size()) {
        cout << "Error: Matrices must be of the same size to perform subtraction." << endl;
        return;
    }

    cout << "Difference of matrices:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix1[i][j] - matrix2[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to multiply two matrices
void multiplyMatrices(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2) {
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();
    int rows2 = matrix2.size();
    int cols2 = matrix2[0].size();

    if (cols1 != rows2) {
        cout << "Error: Number of columns in the first matrix should be equal to the number of rows in the second matrix." << endl;
        return;
    }

    cout << "Product of matrices:" << endl;
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            int sum = 0;
            for (int k = 0; k < cols1; ++k) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            cout << sum << " ";
        }
        cout << endl;
    }
}
int main() {
    int rows1, cols1, rows2, cols2;
    cout << "Enter the number of rows and columns for matrix1: ";
    cin >> rows1 >> cols1;

    cout << "Enter elements of first matrix: " << endl;
    vector<vector<int>> matrix1(rows1, vector<int>(cols1));
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            cin >> matrix1[i][j];
        }
    }

    cout << "Enter the number of rows and columns for matrix1: ";
    cin >> rows2>> cols2;

    cout << "Enter elements of second matrix: " << endl;
    vector<vector<int>> matrix2(rows2, vector<int>(cols2));
    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < cols2; ++j) {
            cin >> matrix2[i][j];
        }
    }

    cout << "First matrix:" << endl;
    printMatrix(matrix1);
    cout << "Second matrix:" << endl;
    printMatrix(matrix2);

    addMatrices(matrix1, matrix2);
    subtractMatrices(matrix1, matrix2);
    multiplyMatrices(matrix1, matrix2);

    return 0;
}
