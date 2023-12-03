// Online C compiler to run C program online
#include <stdio.h>

void addMat(int rows,int cols,int m1[rows][cols],int m2[rows][cols],int res[rows][cols],int i,int j){
    if(j == cols){
        addMat(rows,cols,m1,m2,res,i+1,0);
        return;
    }
    if(i == rows){
        return;
    }
    
    res[i][j] = m1[i][j]+m2[i][j];
    addMat(rows,cols,m1,m2,res,i,j+1);
}

int main() {
    
    printf("Enter the rows and cols : \n");
    int rows , cols ;
    scanf("%d%d",&rows,&cols);
    int mat1[rows][cols];
    printf("Enter the elements of the matrix : \n");
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            scanf("%d",&mat1[i][j]);
        }
    }
    printf("Enter the elements of the matrix : \n");
    int mat2[rows][cols];
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            scanf("%d",&mat2[i][j]);
        }
    }
    int res[rows][cols];
    addMat(rows,cols,mat1,mat2,res,0,0);
    printf("Resultant : \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}