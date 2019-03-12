#include "header.h"

int main() {		
	int v, e, a, b, w, i;
	scanf("%d %d", &v, &e);
	struct Graph* graph = initGraph(v);
	for (i = 0; i < e; i++) {
		scanf("%d %d %d", &a, &b, &w);
		connectVertexes(graph, a, b, w);
	}
	printf("%d", primAlgorithm(graph));
	return 0;
}