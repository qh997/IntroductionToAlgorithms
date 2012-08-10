#include <stdio.h>
#include <stdlib.h>

#define LEFT(i) ((2 * i) + 1)
#define RIGHT(i) (LEFT(i) + 1)

void max_heapify(int *A, int i, int heap_size);
void build_max_heap(int *A, int lengthA);
void heap_sort(int *A, int lengthA);
void print_array(int *A, int lengthA);

int main()
{
    printf("MAX-HEAPIFY\n");
    int array_mh[] = {16,4,10,14,7,9,3,2,8,1};
    print_array(array_mh, sizeof(array_mh) / sizeof(int));
    max_heapify(array_mh, 1, sizeof(array_mh) / sizeof(int));
    print_array(array_mh, sizeof(array_mh) / sizeof(int));

    printf("\nHEAP-SORT\n");
    int array_hs[] = {4,1,3,2,16,9,10,14,8,7};
    print_array(array_hs, sizeof(array_hs) / sizeof(int));
    heap_sort(array_hs, sizeof(array_hs) / sizeof(int));
    print_array(array_hs, sizeof(array_hs) / sizeof(int));
}

void max_heapify(int *A, int i, int heap_size)
{
    int l = LEFT(i);
    int r = RIGHT(i);
    int largest = i;

    if (l <= heap_size && A[l] > A[i])
        largest = l;
    else
        largest = i;

    if (r <= heap_size && A[r] > A[largest])
        largest = r;

    if (largest != i)
    {
        int tmp = A[i];
        A[i] = A[largest];
        A[largest] = tmp;
        
        max_heapify(A, largest, heap_size);
    }
}

void build_max_heap(int *A, int lengthA)
{
    for (int i = (int)((lengthA - 1) / 2); i >= 0; i--)
        max_heapify(A, i, lengthA - 1);
}

void heap_sort(int *A, int lengthA)
{
    build_max_heap(A, lengthA);
    int heap_size = lengthA - 1;
    for (int i = lengthA - 1; i > 0; i--)
    {
        int tmp = A[0];
        A[0] = A[i];
        A[i] = tmp;

        max_heapify(A, 0, --heap_size);
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