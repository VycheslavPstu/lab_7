#include <stdio.h>
#include <cmath>


float side_length(int *M, int *N){
    return pow(pow(M[0]-N[0], 2)+pow(M[1]-N[1], 2), 0.5);
}


bool belong(int *M, int *A, int *B, int *C){
    int AB, BC, AC;
    if (((M[0]-A[0])/(B[0]-A[0]) == (M[1]-A[1])/(B[1]-A[1])) or ((M[0]-B[0])/(C[0]-B[0]) == (M[1]-B[1])/(C[1]-B[1])) or ((M[0]-A[0])/(A[0]-C[0]) == (M[1]-A[1])/(A[1]-C[1]))){
        return true;
    }
    else{
        return false;
    }
}


bool belong2(int *M, int n, ...){
    int vertex_1[2], vertex_2[2], vertex_3[2];
    printf("в. 1(x, y): "); scanf("%d%d", &vertex_3[0], &vertex_3[1]);
    vertex_2[0] = vertex_3[0];
    vertex_2[1] = vertex_3[1];
    for (int i = 2; i <= n; i++){
        vertex_1[0] = vertex_2[0];
        vertex_1[1] = vertex_2[1];
        if ((M[0]-vertex_1[0])/(vertex_2[0]-vertex_1[0]) == (M[1]-vertex_1[1])/(vertex_2[1]-vertex_1[1])){
            return true;
        }
    }
    if ((M[0]-vertex_1[0])/(vertex_3[0]-vertex_1[0]) == (M[1]-vertex_1[1])/(vertex_3[1]-vertex_1[1])){
            return true;
    }
    return false;
}


int main(){
    int M[2], N[2], A[2], B[2], C[2], n;
    printf("Задание 1\nM(x, y): "); scanf("%d%d", &M[0], &M[1]);
    printf("N(x, y): "); scanf("%d%d", &N[0], &N[1]);
    printf(" __ \n|MN| = %f", side_length(M, N));
   
    printf("\n\nЗадание 2\nт. M(x, y): "); scanf("%d%d", &M[0], &M[1]);
    printf("в. A(x, y): "); scanf("%d%d", &A[0], &A[1]);
    printf("в. B(x, y): "); scanf("%d%d", &B[0], &B[1]);
    printf("в. C(x, y): "); scanf("%d%d", &C[0], &C[1]);
    if (belong(M, A, B, C) == true){
        printf("\nM ∊ △ABC");
    }
    else{
        printf("\nM ∉ △ABC");
    }
    printf("\n\nЗадание 3\nт. M(x, y): "); scanf("%d%d", &M[0], &M[1]);
    printf("Количество вершин: "); scanf("%d", &n);
    if (belong2(M, n) == true){
        printf("\nM ∊");
    }
    else{
        printf("\nM ∉");
    }
    return 0;
    
}
