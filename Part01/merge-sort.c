#include <stdio.h>
#include <stdlib.h>

void merge(int *A, int p, int q, int r);
void merge_sort(int *A, int p, int r);
void print_array(int *A, int lengthA);

int main()
{
    printf("MERGE\n");
    int array_merge[] = {2,4,5,7,9,1,2,3,6,8};
    print_array(array_merge, sizeof(array_merge) / sizeof(int));
    merge(array_merge, 0, 4, sizeof(array_merge) / sizeof(int) - 1);
    print_array(array_merge, sizeof(array_merge) / sizeof(int));

    printf("\nMERGE-SORT\n");
    int array_mergesort[] = {5, 9, 2, 8, 7, 4, 6, 1, 2, 3};
    print_array(array_mergesort, sizeof(array_mergesort) / sizeof(int));
    merge_sort(array_mergesort, 0, sizeof(array_mergesort) / sizeof(int) - 1);
    print_array(array_mergesort, sizeof(array_mergesort) / sizeof(int));
}

void merge(int *A, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int *L = (int *)malloc(sizeof(int) * n1);
    int *R = (int *)malloc(sizeof(int) * n2);

    for (int l = 0; l < n1; l++)
        *(L + l) = A[p + l];
    for (int r = 0; r < n2; r++)
        *(R + r) = A[q + r + 1];

    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2)
        if (L[i] <= R[j])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];

    while (i < n1)
        A[k++] = L[i++];

    while (j < n2)
        A[k++] = R[j++];

    free(L);
    free(R);
}

void merge_sort(int *A, int p, int r)
{
    if (p < r)
    {
        int q = (int)((p + r) / 2);
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

void print_array(int *A, int lengthA)
{
    for (int i = 0; i < lengthA; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}