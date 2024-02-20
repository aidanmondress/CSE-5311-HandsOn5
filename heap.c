#include <stdio.h>
#include <stdlib.h>

/*
 * heap.c
 *
 *  Created on: Feb 20, 2024
 *      Author: aimon
 */

struct HeapStruct
{
    int* arr;
    int size;
    int capacity;
};
typedef struct HeapStruct heap;

heap* heapInit(int* nums, int n)
{
    heap* hp = (heap*)malloc(sizeof(heap));
    int i = 0;
    hp->size = 0;
    hp->capacity = n;
    hp->arr = (int*)malloc(n * sizeof(int));

    for(i = 0; i < n; i++)
    {
        hp->arr[i] = nums[i];
    }
    hp->size = i;
    i = (hp->size - 2) / 2;

    while(i >= 0)
    {
        heapify(hp, i);
        i--;
    }

    return hp;
}

void heapify(heap* hp, int i)
{
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    int min = i;

    if(l >= hp->size || l < 0)
        l = -1;
    if(r >= hp->size || r < 0)
        r = -1;

    if(hp->arr[l] < hp->arr[i] && l != -1)
        min = l;
    if(hp->arr[r] < hp->arr[min] && r != -1)
        min = r;

    if(min != i)
    {
        int temp = hp->arr[min];
        hp->arr[min] = hp->arr[i];
        hp->arr[i] = temp;

        heapify(hp, min);
    }
}

int popRoot(heap* hp)
{
    if(hp->size == 0)
        return -1;

    int root = hp->arr[0];

    hp->arr[0] = hp->arr[hp->size - 1];
    hp->size--;

    heapify(hp, 0);
    return root;
}

void printHeap(heap* hp)
{
	for(int i = 0; i < hp->size; i++)
        printf("%d ", hp->arr[i]);
    printf("\n");
}

int main()
{
	int arr[11] = {15, 1, 7, 20, 13, 4, 11, 3, 10, 12, 24};
	heap* h = heapInit(arr, 11);

	printf("Initial Heap: ");
	printHeap(h);

	popRoot(h);

	printf("Heap After Root is Popped: ");
	printHeap(h);

	return 0;
}
