#include<stdio.h>
#include<stdlib.h>

double **allocate(int rows,int cols){                               //memory allocation
    int **arr = (int **)malloc(rows * sizeof(int *));
    for(int i = 0;i < rows;i++){
        arr[i] = (int *)malloc(cols * sizeof(int));
    }
    return arr;
}

void inputMatrix(double** matrix, int rows, int cols) {             //taking matrix
    printf("Enter matrix values:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
}


void displayMatrix(double** matrix, int rows, int cols) {
    printf("Matrix:\n");                                                //display func
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2lf\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// multiplying .......
double** multiplyMatrices(double** mat1, int rows1, int cols1, double** mat2, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Matrix multiplication not possible.\n");
        return NULL;
    }

    double** result = allocate(rows1, cols2);

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0.0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return result;
}



int main(){
    
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    if (cols1 != rows2) {
        printf("Matrix multiplication  not possible.\n");
        return 1;
    }

    double** matrix1 =  allocate(rows1, cols1);
    double** matrix2 = allocate(rows2, cols2);

    inputMatrix(matrix1, rows1, cols1);
    inputMatrix(matrix2, rows2, cols2);

    double** result = multiplyMatrices(matrix1, rows1, cols1, matrix2, rows2, cols2);

    
    if (result != NULL) {
            displayMatrix(result, rows1, cols2);
        }
    return 0;
}
