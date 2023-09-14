#include <stdio.h>

struct Element {
    int row, col, value;
};

int main() {
    int m, n; 
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &m, &n);

    
    int sparseMatrix[m][n];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &sparseMatrix[i][j]);
        }
    }


    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (sparseMatrix[i][j] != 0) {
                count++;
            }
        }
    }

    struct Element compactForm[count];
    int k = 0; 

    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (sparseMatrix[i][j] != 0) {
               
               compactForm[k].col = j;
                compactForm[k].row = i; 
                compactForm[k].value = sparseMatrix[i][j];
                k++;
            }
        }
    }


    printf("Compact form of the matrix:\n");
    printf("Column\tRow\tValue\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%d\t%d\n", compactForm[i].col, compactForm[i].row, compactForm[i].value);
    }

    return 0;
}
