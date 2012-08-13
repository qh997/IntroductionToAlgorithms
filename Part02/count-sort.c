#include <stdio.h>
#include <stdlib.h>

void count_sort(int *A, int *B, int k, int l);
void print_array(int *A, int lengthA);

int main()
{
    printf("COUNT-SORT\n");
    int array_cs[] = {2,5,3,0,2,3,0,3};
    int result[8] = {0};
    print_array(array_cs, sizeof(array_cs) / sizeof(int));
    count_sort(array_cs, result, 5, sizeof(array_cs) / sizeof(int));
    print_array(result, sizeof(array_cs) / sizeof(int));
}

void count_sort(int *A, int *B, int k, int l)
{
    int *C = (int *)malloc(sizeof(int) * (k + 1));
    for (int i = 0; i <= k; i++)
        C[i] = 0;

    for (int j = 0; j < l; j++)
        C[A[j]] = C[A[j]] + 1;

    for (int i = 1; i <= k; i++)
    	C[i] = C[i] + C[i - 1];

    for (int j = l - 1; j >= 0; j--)
    {
        B[C[A[j]] - 1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }

    free(C);
}

void print_array(int *A, int lengthA)
{
    for (int i = 0; i < lengthA; i++)
    {
        printf("%3d", A[i]);
    }
    printf("\n");
}