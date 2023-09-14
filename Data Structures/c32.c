#include <stdio.h>

struct Element {
    int row, col, value;
};

int main() {
    int m, n, count;
    printf("Enter the number of rows, columns, and non-zero elements in the compact form: ");
    scanf("%d%d%d", &m, &n, &count);

    struct Element compactForm[count];

    printf("Enter the elements in compact form (Column Row Value):\n");
    for (int i = 0; i < count; i++) {
        scanf("%d%d%d", &compactForm[i].col, &compactForm[i].row, &compactForm[i].value);
    }

    int sparseMatrix[m][n];

    // Initialize the sparse matrix with zeros
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sparseMatrix[i][j] = 0;
        }
    }

    // Fill in the sparse matrix using compact form data
    for (int i = 0; i < count; i++) {
        sparseMatrix[compactForm[i].row][compactForm[i].col] = compactForm[i].value;
    }

    printf("The sparse matrix is:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", sparseMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
