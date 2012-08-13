#include <stdio.h>
#include <stdlib.h>

int partition(int *A, int p, int r);
void quick_sort(int *A, int p, int r);
void print_array(int *A, int lengthA);

int main()
{
    printf("QUICK-SORT\n");
    int array_qs[] = {2,8,7,1,3,5,6,4};
    print_array(array_qs, sizeof(array_qs) / sizeof(int));
    quick_sort(array_qs, 0, sizeof(array_qs) / sizeof(int) - 1);
    print_array(array_qs, sizeof(array_qs) / sizeof(int));
}

int partition(int *A, int p, int r)
{
    int x = A[r];
    int i = p;

    for (int j = p; j < r; j++)
    {
        if (A[j] <= x)
        {
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
            i++;
        }
    }

    int tmp = A[i];
    A[i] = A[r];
    A[r] = tmp;

    return(i);
}

void quick_sort(int *A, int p, int r)
{
    if (p < r)
    {
        int q = partition(A, p, r);
        quick_sort(A, p, q - 1);
        quick_sort(A, q + 1, r);
    }
}

void print_array(int *A, int lengthA)
{
    for (int i = 0; i < lengthA; i++)
    {
        printf("%3d", A[i]);
    }
    printf("\n");
}