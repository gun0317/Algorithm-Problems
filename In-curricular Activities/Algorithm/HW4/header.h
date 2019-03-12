#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Vertex Vertex;
typedef struct Graph Graph;
typedef struct MinHeap MinHeap;

struct Vertex {
	int name;
	int key;						
	int *connectedVertexWeights;										// Store weights of connected vertexex.
};

struct Graph {
	int totalVertexNumber;
	Vertex **vertexList;
};

struct MinHeap {
	int remainVertexNumber;
	int *position;
	int totalVertexNumber;
	Vertex **vertexList;
};

// Implemented Functions
Vertex *initVertex(Vertex *Vert, int N, int V);
Graph *initGraph(int V);
void connectVertexes(Graph *G, int ParaA, int ParaB, int ParaW);
MinHeap *initMinHeap(int V);
void swapVertex(Vertex **ParaA, Vertex **ParaB);						// Usage: swapVertex(&VertA, &VertB);
int isEmptyHeap(MinHeap *M);
int isInMinHeap(MinHeap *M, int V);

// Homework 4C
void minHeapify(MinHeap *M, int Index);									// Min-heapify the heap at Index.
Vertex *extractMin(MinHeap *M);											// Extract minimum vertex from heap and return it. 
void decreaseKey(MinHeap *M, int V, int Key);							// Decrease key value of vertex V.
void addVertexToHeap(MinHeap *M, Graph *G, int V);						// Get Vertex from graph and add it to heap.
int primAlgorithm(Graph *G);											// Run Prim's algorithm and return sum of MSP's edge weights.