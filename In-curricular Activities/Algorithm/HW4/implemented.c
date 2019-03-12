#include "header.h"

Vertex *initVertex(Vertex *Vert, int N, int V) {
	Vert->name = N;
	Vert->key = INT_MAX;
	Vert->connectedVertexWeights = (int*)malloc(sizeof(int)*V);
	for (int i = 0; i < V; i++)
		Vert->connectedVertexWeights[i] = INT_MAX;
	return Vert;
}

Graph *initGraph(int V) {
	Graph *graph = (Graph*)malloc(sizeof(Graph));
	graph->totalVertexNumber = V;
	graph->vertexList = (Vertex**)malloc(sizeof(Vertex*)*V);
	for (int i = 0; i < V; i++) {
		graph->vertexList[i] = (Vertex*)malloc(sizeof(Vertex));
		initVertex(graph->vertexList[i], i, V);
	}
	return graph;
}

void connectVertexes(Graph *G, int ParaA, int ParaB, int ParaW) {
	Vertex *tempA, *tempB;
	tempA = G->vertexList[ParaA];
	tempB = G->vertexList[ParaB];
	tempA->connectedVertexWeights[tempB->name] = ParaW;
	tempB->connectedVertexWeights[tempA->name] = ParaW;
}

MinHeap *initMinHeap(int V) {
	MinHeap *minheap = (MinHeap*)malloc(sizeof(MinHeap));
	minheap->position = (int*)malloc(sizeof(int)*V);
	minheap->vertexList = (Vertex**)malloc(sizeof(Vertex*)*V);
	minheap->remainVertexNumber = 0;
	minheap->totalVertexNumber = V;
	return minheap;
}

void swapVertex(Vertex **ParaA, Vertex **ParaB) {
	Vertex *temp = *ParaB;
	*ParaB = *ParaA;
	*ParaA = temp;
}

int isEmptyHeap(MinHeap* M) {
	return M->remainVertexNumber == 0;
}

int isInMinHeap(MinHeap *M, int V) {
	return M->position[V] < M->remainVertexNumber;
}