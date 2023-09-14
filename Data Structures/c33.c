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

    // Find the dimensions of the transposed matrix
    int transposedM = n;
    int transposedN = m;

    struct Element transposedForm[count];

    // Compute the transposed compact form
    for (int i = 0; i < count; i++) {
        transposedForm[i].col = compactForm[i].row;
        transposedForm[i].row = compactForm[i].col;
        transposedForm[i].value = compactForm[i].value;
    }

    printf("The transpose of the compact form is:\n");
    printf("Column\tRow\tValue\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%d\t%d\n", transposedForm[i].col, transposedForm[i].row, transposedForm[i].value);
    }

    return 0;
}
