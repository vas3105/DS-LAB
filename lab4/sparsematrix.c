#include <stdio.h>
struct matrix {
    int row, col, value;
};
void sparse(int m, int n, int a[m][n], int count, struct matrix result[]) {
    int k = 1;
    result[0].row = m;
    result[0].col = n;
    result[0].value = count;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != 0) {
                result[k].row = i;
                result[k].col = j;
                result[k].value = a[i][j];
                k++;
            }
        }
    }

    printf("The sparse matrix is:\n");
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i <= count; i++) {
        printf("%d\t%d\t%d\n", result[i].row, result[i].col, result[i].value);
    }
}

// Function to perform fast transpose of the sparse matrix
void transpose(struct matrix sparse[], struct matrix transposed[]) {
    int numTerms = sparse[0].value;
    int numCols = sparse[0].col;

    transposed[0].row = sparse[0].col;
    transposed[0].col = sparse[0].row;
    transposed[0].value = sparse[0].value;

    int total[numCols], index[numCols];

    for (int i = 0; i < numCols; i++) total[i] = 0;

    for (int i = 1; i <= numTerms; i++) total[sparse[i].col]++;

    index[0] = 1;
    for (int i = 1; i < numCols; i++) index[i] = index[i - 1] + total[i - 1];

    for (int i = 1; i <= numTerms; i++) {
        int position = index[sparse[i].col]++;
        transposed[position].row = sparse[i].col;
        transposed[position].col = sparse[i].row;
        transposed[position].value = sparse[i].value;
    }
    printf("\nThe transposed sparse matrix is:\n");
    printf("Coloum\tRow\tValue\n");
    for (int i = 0; i <= numTerms; i++) {
        printf("%d\t%d\t%d\n", transposed[i].row, transposed[i].col, transposed[i].value);
    }
}
int main() {
    int m, n, count = 0;

    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &m, &n);

    int a[m][n];

    printf("Enter the values of the elements in the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] != 0) {
                count++;
            }
        }
    }
    struct matrix sparseMatrix[count + 1];
    struct matrix transposedMatrix[count + 1];
    sparse(m, n, a, count, sparseMatrix);
    transpose(sparseMatrix, transposedMatrix);
    return 0;
}

