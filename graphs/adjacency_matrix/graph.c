#include <stdio.h>
#include <stdlib.h>

//declare globally
int V = 5;

void initzero(int matrix[V][V])
{
    for (int i=0; i<V ; i++)
        for (int j=0; j<V; j++)
            matrix[i][j] = 0;   
}

void insert(int matrix[V][V], int i, int j)
{
    matrix[i][j] = 1;
    matrix[j][i] = 1;
}

void print(int arr[V][V]) 
{ 
    for (int i = 0; i < V; i++){ 
        for (int j = 0; j < V; j++) 
            printf("%d ", arr[i][j]); 
        printf("\n");}
} 

int main(void)
{
    
    int matrix[V][V];

    initzero(matrix);

    insert(matrix, 0, 4);
    insert(matrix, 0, 1);
    insert(matrix, 1, 4);
    insert(matrix, 1, 3);
    insert(matrix, 1, 2);
    insert(matrix, 2, 4);
    insert(matrix, 3, 3);

    print(matrix);

}