#include <stdlib.h>
#include <math.h>
#include "determinant.h"

void skipRow(int **matrix, int size, int exclude_row, int** return_matrix){
    int skip_value = 0;
    for(int i=0; i<size-1;i++){
        if(i==exclude_row){
            skip_value++;
        }
        return_matrix[i] = matrix[i+skip_value];
    }
}

int getDeterminant(int **matrix, int size, int* error){
    if(size<1){
        *error = HAS_ERROR;
        return 0;
    }
    if(size==1){
        return matrix[0][0];
    }
    else if(size==2){
        *error = NO_ERROR;
        int ret = ((matrix[0][0]) * (matrix[1][1]) - (matrix[0][1]) * (matrix[1][0]));
        return ret;
    }else {
        int sum = 0;
        for (int i = 0; i<size; i++){
            int** return_matrix = (int**) malloc((size-1)*sizeof(int*));
            skipRow(matrix, size, i, return_matrix);
            int det = getDeterminant(return_matrix, size-1, error);
            sum+= (matrix[i][size-1]) * (pow(-1, i)) * (det);
        }
        *error = NO_ERROR;
        if(size%2){
            return sum;
        }else{
            return -sum;
        }
    }

}


