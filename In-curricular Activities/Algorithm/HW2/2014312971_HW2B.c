#include <stdio.h>


void Min_Heapify(int *arr, int i, int x, int size);
int LChild(int i, int x);
int Heap_Size(int *arr);
void Build_Min_Heap(int *arr, int x, int size);
void SortAndPrint(int *arr, int x, int size);
void SWAP(int *arr, int i, int j);

int main(void)
{
	int arr[200] = { 0, }, x, i = 0;
	scanf("%d", &x);
	fflush(stdin);
	do
	{
		scanf(" %d", &arr[++i]);	//save the input to arr, starting index is 1.
	} while (getc(stdin) == ' ');

	int size = Heap_Size(arr);
	SortAndPrint(arr, x, size);
	return 0;
}


void Min_Heapify(int *arr, int i, int x, int size)	//done under assumption that children are already
{
	int firstChild, smallest = 0;
	firstChild = LChild(i, x);

	if (firstChild <= size && arr[firstChild] < arr[i])	//compare target node(i) with the first child(left_most child)
		smallest = firstChild;

	else
		smallest = i;
	for (int j = 1; j < x; j++)			//compare the remaining children with current 'smallest' value. number of iteration depends on x
		if ((firstChild + j) <= size && arr[firstChild + j] < arr[smallest])
			smallest = firstChild + j;

	if (smallest != i)		//this means the order have to be changed.
	{
		SWAP(arr, i, smallest);		//ordinary SWAP function
		Min_Heapify(arr, smallest, x, size);		//recursively
	}
}

int LChild(int i, int x)
{
	return (i*x - (x - 2));		//index of first child : 3-ary = 3i-1//4-ary = 4i-2// 5-ary = 5i-3.
}

int Heap_Size(int *arr)			//returns the size of heap
{
	int i, cnt = 0;
	for (i = 1; i < 200; i++)
	{
		if (arr[i] == 0)
			break;
		cnt++;
	}
	return cnt;
}



void Build_Min_Heap(int *arr, int x, int size)
{
	int i;
	for (i = size; i > 0; i--)
		Min_Heapify(arr, i, x, size);
}


void SortAndPrint(int *arr, int x, int size)		//almost same as heapsort.
{
	int j;
	Build_Min_Heap(arr, x, size);
	for (j = 1; j<size + 1; j++)
		printf("%d ", arr[j]);
	printf("\n");
	int i;
	for (i = size; i > 1; )
	{
		SWAP(arr, 1, i);
		Min_Heapify(arr, 1, x, --i);			//the only difference is sorting with Min_heapify, printing the value in progress.
		for (j = 1; j < Heap_Size(arr)+1; j++)
			printf("%d ", arr[j]);
		printf("\n");
	}
}

void SWAP(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
