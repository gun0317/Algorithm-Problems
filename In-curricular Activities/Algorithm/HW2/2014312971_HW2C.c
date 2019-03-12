//2014312971 ÀÌ¿µ°Ç
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_QUEUE	100

typedef enum { false, true } bool;


typedef struct {
	int front, rear;
	int items[MAX_QUEUE];
} Queue;

// Make queue empty.
void InitQueue(Queue *pqueue);
// Check whether queue is full.
bool IsFull(Queue *pqueue);
// Check whether queue is empty.
bool IsEmpty(Queue *pqueue);

// Read the item at the front.
int Peek(Queue *pqueue);
// Insert an item at the rear.
void EnQueue(Queue *pqueue, int item);
// Delete an item at the front.
void DeQueue(Queue *pqueue);

void radixSort(char *arr,int size);

int len = 0;
int main(void)
{
	char input[300];
	int i, size = 1;
	scanf(" %[^\n]s", input);
	len = strlen(input);
	for (i = 0; i < 300; i++)				//counting the number of elements.
	{
		if (input[i] == ' ')
			size++;
		if (input[i] == '\0')
			break;
	}

	radixSort(input, size);

	return 0;

}
//2004006457 C006000329 700C000657 400200083F A008000436 F005000720 D00B000355
//1234578072 2081726430 3001010019 2345300431 2000030400
void radixSort(char *arr, int size)
{
	Queue queue[16];
	char *temp = (char*)malloc(sizeof(char)*len);   //to temporary store the arr
	int *result = (int*)malloc(sizeof(int)*size);   //to save the index
	for (int q = 0; q < 16; q++)
		InitQueue(&queue[q]);
	int i,j,k,h,index=0;
	for (j = 9; j > -1; j--)        //10digits
	{
		for (i = 0; i < size; i++)  //for number of elements
		{
			switch (arr[j + 11 * i])        //the value of array at certain index.
			{                                  //EnQueue the index to queue.
			case '0':
			{
				EnQueue(&queue[0], i);
				break;
			}
			case '1':
			{
				EnQueue(&queue[1], i);
				break;
			}
			case '2':
			{
				EnQueue(&queue[2], i);
				break;
			}
			case '3':
			{
				EnQueue(&queue[3], i);
				break;
			}
			case '4':
			{
				EnQueue(&queue[4], i);
				break;
			}
			case '5':
			{
				EnQueue(&queue[5], i);
				break;
			}
			case '6':
			{
				EnQueue(&queue[6], i);
				break;
			}
			case '7':
			{
				EnQueue(&queue[7], i);
				break;
			}
			case '8':
			{
				EnQueue(&queue[8], i);
				break;
			}
			case '9':
			{
				EnQueue(&queue[9], i);
				break;
			}
			case 'A':
			{
				EnQueue(&queue[10], i);
				break;
			}
			case 'B':
			{
				EnQueue(&queue[11], i);
				break;
			}
			case 'C':
			{
				EnQueue(&queue[12], i);
				break;
			}
			case 'D':
			{
				EnQueue(&queue[13], i);
				break;
			}
			case 'E':
			{
				EnQueue(&queue[14], i);
				break;
			}
			case 'F':
			{
				EnQueue(&queue[15], i);
				break;
			}
			}
		}					//store the values in Queue[0] to Queue[15].(bucket-ing)
		index = 0;
		for (k = 0; k < 16; k++)            //for every queue
		{
			while(!IsEmpty(&queue[k]))
			{
				for(h=0;h<10;h++)
					printf("%c", arr[h + (Peek(&queue[k]))*11]);    //to print the element (10 digits)
				printf(" ");
				result[index++] = Peek(&queue[k]);     //storing the index in integer array
				DeQueue(&queue[k]);
			}
		}
		printf("\n");
		for (h = 0; h < len; h++)
			temp[h] = arr[h];       //copy the arr to temp.
		for (h = 0; h < size; h++)
		{
			for (index = 0; index < 10; index++)
			{
				if (result[h] != 0)
					arr[h * 11 + index] = temp[(result[h]) * 11 + index];   //changing the order of array according to result.
				else
					arr[h * 11 + index] = temp[index];        //exceptional case, when result[h] = 0.
			}
		}

	}

	free(result);
	free(temp);       //free the m allocated memory.
}




// Make queue empty.
void InitQueue(Queue *pqueue)
{
	pqueue->front = pqueue->rear = 0;
}

// Check whether queue is full.
bool IsFull(Queue *pqueue)
{
	return pqueue->front
		== (pqueue->rear + 1) % MAX_QUEUE;
}

// Check whether queue is empty.
bool IsEmpty(Queue *pqueue)
{
	return pqueue->front == pqueue->rear;
}

// Read the item at the front.
int Peek(Queue *pqueue)
{
	if (IsEmpty(pqueue))
		exit(1); //error: empty stack
	return pqueue->items[pqueue->front];
}

// Insert an item at the rear.
void EnQueue(Queue *pqueue, int item)
{
	if (IsFull(pqueue))
		exit(1); //error: stack full
	pqueue->items[pqueue->rear] = item;
	pqueue->rear = (pqueue->rear + 1) % MAX_QUEUE;
}

// Delete an item at the front.
void DeQueue(Queue *pqueue)
{
	if (IsEmpty(pqueue))
		exit(1); //error: empty stack
	pqueue->front = (pqueue->front + 1) % MAX_QUEUE;
}
//3068523305 61617530D7 8010873D73 0643023269 2550895376 FF96377620 3245978375 7356137172 9558584143 1870570322
//9286885317 3390489214 84C1832654 0210979809 7741302226
