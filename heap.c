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
    int arr[];
    int size;
    int capacity;
};
typedef struct HeapStruct heap;

heap* createHeap(int nums[], int n)
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
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    int min = i;

    if(left >= hp->size || left < 0)
        left = -1;
    if(right >= hp->size || right < 0)
        right = -1;

    if(hp->arr[left] < hp->arr[i] && left != -1)
        min = left;
    if(hp->arr[right] < hp->arr[min] && right != -1)
        min = right;

    if(min != i)
    {
        int temp = hp->arr[min];
        hp->arr[min] = hp->arr[i];
        hp->arr[i] = temp;

        heapify(hp, min);
    }
}

int extractMin(heap* hp)
{
    if(hp->size == 0)
        return -1;

    int extract = hp->arr[0];

    hp->arr[0] = hp->arr[hp->size - 1];
    hp->size--;

    heapify(hp, 0);
    return extract;
}

int main()
{

}
