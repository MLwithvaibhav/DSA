bool linearSearch(int mat[][3], int rows, int cols, int key) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == key) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int matrix[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    int rows = 4;
    int cols = 3;

    cout << linearSearch(matrix, rows, cols, 8) << endl;

    return 0;
}











// returning the keys

#include <iostream>
using namespace std;

pair<int,int> linearSearch(int mat[][3], int rows, int cols, int key) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == key) {
                return {i, j}; // row, col ka pair return
            }
        }
    }
    return {-1, -1}; // not found case
}

int main() {
    int matrix[4][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };
    int rows = 4;
    int cols = 3;

    pair<int,int> pos = linearSearch(matrix, rows, cols, 8);

    if (pos.first != -1) {
        cout << "Key found at Row: " << pos.first 
             << ", Col: " << pos.second << endl;
    } else {
        cout << "Key not found" << endl;
    }

    return 0;
}
