#include<stdio.h>
#include <stdlib.h>
#include"determinant.h"

int main(){
    int mats1[] = {2,3,4,5,4};
    int* mat1 = mats1;
    int mats2[] = {3,6,2,4,5};
    int* mat2 = mats2;
    int mats3[] = {4,5,3,6,1};
    int* mat3 = mats3;
    int mats4[] = {4,7,8,5,2};
    int* mat4 = mats4;
    int mats5[] = {5,3,6,5,7};
    int* mat5 = mats5;
    int* matris[] = {mat1, mat2, mat3, mat4, mat5};
    int** matrix = matris;
    int *error = (int*) malloc(sizeof(int));
    int ret = getDeterminant(matrix, 5, error);
    printf("Determinant is %d\n", ret);

}