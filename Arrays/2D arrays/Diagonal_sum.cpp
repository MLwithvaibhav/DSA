int diagonalSum(int mat[][4], int n) {   // O(n * n)
    int sum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                sum += mat[i][j];
            } else if (j == n - i - 1) {
                sum += mat[i][j];
            }
        }
    }

    return sum;
}

int main() {
    int matrix[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int n = 4;
}









// #diagonal sum with O(n) time complexity
int diagonalSum(int mat[][4], int n) {   // O(n)
    int sum = 0;

    // pd: j = i
    // sd: j = n - i - 1

    for (int i = 0; i < n; i++) {
        // Primary diagonal element add
        sum += mat[i][i];

        // Secondary diagonal element add, but avoid double counting center element (for odd n)
        if (i != n - i - 1) {
            sum += mat[i][n - i - 1];
        }
    }

    return sum;
}
