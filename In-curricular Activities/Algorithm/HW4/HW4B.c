#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE	100
typedef enum { false, true } bool;

/*
10 8
A/B/C/D/E/F/G/H/I/J
A/D
D/E
D/F
D/G
B/G
C/H
H/I
I/J
*/

typedef struct {
	int front, rear;
	int items[MAX_QUEUE];
} Queue;

typedef struct {
	char name[20];
	int rank;
} Animal;

// Make queue empty.
void InitQueue(Queue *pqueue);
// Check whether queue is full.
bool IsQFull(Queue *pqueue);
// Check whether queue is empty.
bool IsQEmpty(Queue *pqueue);

// Read the item at the front.
int QPeek(Queue *pqueue);
// Insert an item at the rear.
void EnQueue(Queue *pqueue, int item);
// Delete an item at the front.
void DeQueue(Queue *pqueue);

void BFS(int** pgraph, int N, int *rank);

int main(void)
{
	int N, C;
	int i = 0;
	char str[2000];
	scanf("%d %d", &N, &C);

	//C�� ���߾� comparison���� ������ 2���� char �迭 temp�� ����
	char **temp;
	temp = (char**)malloc(sizeof(char**)*C);
	temp[0] = (char*)malloc(sizeof(char *)*C * 50);
	for (i = 1; i < C; i++)
		temp[i] = temp[i - 1] + 50;


	scanf(" %[^\n]s", &str);
	for (i = 0; i < C; i++)
		scanf(" %[^\n]s", temp[i]);	//comparison�� �״�� �Է¹޴´�.

	Animal *animal = (Animal*)malloc(sizeof(Animal*));

	//N X N ��� �Ҵ� (adjacency matrix)
	int **arr;
	arr = (int**)malloc(sizeof(int**)*N);
	arr[0] = (int*)malloc(sizeof(int *)*N*N);
	for (i = 1; i < N; i++)
		arr[i] = arr[i - 1] + N;

	//matrix �ʱ�ȭ
	for (i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			arr[i][j] = 0;



	//temp���� �̸�/�̸� ���̹Ƿ� �̸����� ����� ������ ������� comp �Ҵ�
	char **comp;
	comp = (char**)malloc(sizeof(char**) * 2 * C);
	comp[0] = (char*)malloc(sizeof(char *)*C * 2 * 20);
	for (i = 1; i < (2 * C); i++)
		comp[i] = comp[i - 1] + 20;





	char *ptr = strtok(str, "/");	//"/"�� �������� str�� �и�

	i = 0;
	while (ptr != NULL)
	{
		strcpy(animal[i++].name, ptr);
		ptr = strtok(NULL, "/");	//������ �ߴ� �и� �������� �ݺ�
	}								//strtok�� �̿��ؼ� �и��� string�� names�� ���� ����

	
	i = 0;
	for (int j = 0; j < C; j++)
	{
		strcpy(comp[i++], strtok(temp[j], "/"));	//names�� ���������� "/"�� �������� ������ ���� �����Ѵ�.
		strcpy(comp[i++], strtok(NULL, "/"));
	}

	for (int j = 0; j < 2 * C; j += 2)
		for (i = 0; i < N; i++)
			if (strcmp(animal[i].name,comp[j]) == 0)
				//*animal[i].name == *comp[j])
				for (int k = 0; k < N; k++)
					if (strcmp(animal[k].name, comp[j+1]) == 0)
						//*animal[k].name == *comp[j + 1])
						arr[i][k] = 1;					
	//comp�� ����� ������ �������� names�� ���ϸ� adjacency matrix�� �ϼ��Ѵ�


	////adjacency matrix ���
	/*for (i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%d  ", arr[i][j]);
		printf("\n");
	}*/

	//rank�� �ӽ÷� ������ �ڷᱸ�� ����
	int* rank = (int *)malloc(sizeof(int)* N);
	for (int i = 0; i < N; i++)
		rank[i] = 0;


	BFS(arr, N, rank);
	for (i = 0; i < N; i++)
		animal[i].rank = rank[i];

	//sorting in alphabetical order(Selection)
	int t;
	char temp2[25] = { NULL, };
	for (i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
			if (strcmp(animal[i].name, animal[j].name) > 0)
			{
				strcpy(temp2, animal[i].name);
				strcpy(animal[i].name, animal[j].name);
				strcpy(animal[j].name, temp2);

				t = animal[i].rank;
				animal[i].rank = animal[j].rank;
				animal[j].rank = t;
			}
	}

	//stablility�� �����ϸ鼭 rank������ �ٽ� ����(bubble)
	for (i = N - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
			if (animal[j].rank > animal[j+1].rank)
			{
				strcpy(temp2, animal[j].name);
				strcpy(animal[j].name, animal[j+1].name);
				strcpy(animal[j+1].name, temp2);

				t = animal[j].rank;
				animal[j].rank = animal[j+1].rank;
				animal[j+1].rank = t;
			}
	}


	for (i = 0; i < N; i++)
		printf("%d %s\n", animal[i].rank,animal[i].name);

	/*5 4
	Raccoon dog/Raccoon/Red Panda/Dog/Panda
	Raccoon/Red Panda
	Raccoon/Raccoon dog
	Red Panda/Panda
	Raccoon dog/Dog
	*/


	free(comp[0]);
	free(comp);
	free(temp[0]);
	free(temp);
	free(arr[0]);
	free(arr);
	free(rank);

	return 0;
}


void BFS(int** pgraph, int N, int* rank)
{
	Queue queue;
	int vtx;
	int temp = 0;


	InitQueue(&queue);
	for (int j = 0; j < N; j++)
	{
		temp = 0;
		for (int i = 0; i < N; i++)
			temp += pgraph[i][j];
		if (temp == 0)
		{
			rank[j] = 1;		//indegree�� 0�� ���, rank�� ������ 1�̴�.
			EnQueue(&queue, j);
		}
	}
	if (IsQEmpty(&queue))
	{
		printf("Stupid David!");
		exit(1);
	}
	
	// Enqueue the initial vertex.
	while (!IsQEmpty(&queue)) {
		vtx = QPeek(&queue);
		DeQueue(&queue);

		for (int i = 0; i < N; i++)
		{
			if (pgraph[vtx][i] == 1)
			{
				if (rank[i] < rank[vtx] + 1)
					rank[i] = rank[vtx] + 1;
				EnQueue(&queue, i);
			}
		}

	}

}
/*
5 4
R d/R/R P/D/P
R/R d
R P/P
R d/D
D/P
*/

// Make queue empty.
void InitQueue(Queue *pqueue)
{
	pqueue->front = pqueue->rear = 0;
}

// Check whether queue is full.
bool IsQFull(Queue *pqueue)
{
	return pqueue->front
		== (pqueue->rear + 1) % MAX_QUEUE;
}

// Check whether queue is empty.
bool IsQEmpty(Queue *pqueue)
{
	return pqueue->front == pqueue->rear;
}

// Read the item at the front.
int QPeek(Queue *pqueue)
{
	if (IsQEmpty(pqueue))
		exit(1); //error: empty stack
	return pqueue->items[pqueue->front];
}

// Insert an item at the rear.
void EnQueue(Queue *pqueue, int item)
{
	if (IsQFull(pqueue))
		exit(1); //error: stack full
	pqueue->items[pqueue->rear] = item;
	pqueue->rear = (pqueue->rear + 1) % MAX_QUEUE;
}

// Delete an item at the front.
void DeQueue(Queue *pqueue)
{
	if (IsQEmpty(pqueue))
		exit(1); //error: empty stack
	pqueue->front = (pqueue->front + 1) % MAX_QUEUE;
}


