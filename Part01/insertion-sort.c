#include <stdio.h>

void insertion_sort(int *A, int lengthA);
void print_array(int *A, int lengthA);

int main()
{
    int unsorted[] = {5, 2, 7, 4, 6, 1, 3};
    print_array(unsorted, sizeof(unsorted) / sizeof(int));
    insertion_sort(unsorted, sizeof(unsorted) / sizeof(int));
    print_array(unsorted, sizeof(unsorted) / sizeof(int));
}

void insertion_sort(int *A, int lengthA)
{
    for (int j = 1; j < lengthA; j++)
    {
        int key = A[j];
        int i = j - 1;
        while (i >= 0 && A[i] > key)
        {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
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