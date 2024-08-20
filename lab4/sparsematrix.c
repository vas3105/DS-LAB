#include <stdio.h>

struct matrix {
    int row, col, value;
};

void sparse(int m, int n, int a[m][n], int count, struct matrix result[]) {
    int k = 0;
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
    printf("%d\t%d\t%d\n",m,n,k);
    for (int i = 0; i < count; i++) {
        printf("%d\t%d\t%d\n", result[i].row, result[i].col, result[i].value);
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

    struct matrix result[count];

    sparse(m, n, a, count, result);

    return 0;
}
