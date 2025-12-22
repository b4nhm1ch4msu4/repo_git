#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10 // Maximum number of vertices

typedef struct {
  int vertices[MAX_VERTICES];             // Array to store vertex values
  int matrix[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
  int vertexCount; // Current number of vertices in the graph
} Graph;

// Initialize the graph
Graph *initializeGraph() {
  Graph *graph = malloc(sizeof(Graph));
  graph->vertexCount = 0;

  // Initialize the adjacency matrix to 0
  for (int i = 0; i < MAX_VERTICES; i++) {
    for (int j = 0; j < MAX_VERTICES; j++) {
      graph->matrix[i][j] = 0;
    }
  }

  return graph;
}

// Add a vertex to the graph
void addVertex(Graph *graph, int value) {
  if (graph->vertexCount < MAX_VERTICES) {
    graph->vertices[graph->vertexCount++] = value;
  } else {
    printf("Vertex limit reached!\n");
  }
}

// Add an edge between two vertices
void addEdge(Graph *graph, int v1, int v2) {
  int index1 = -1, index2 = -1;

  // Find the indices of the vertices
  for (int i = 0; i < graph->vertexCount; i++) {
    if (graph->vertices[i] == v1)
      index1 = i;
    if (graph->vertices[i] == v2)
      index2 = i;
  }

  if (index1 != -1 && index2 != -1) {
    graph->matrix[index1][index2] = 1;
    graph->matrix[index2][index1] = 1; // For undirected graph
  } else {
    printf("One or both vertices not found!\n");
  }
}

// Remove an edge between two vertices
void removeEdge(Graph *graph, int v1, int v2) {
  int index1 = -1, index2 = -1;

  // Find the indices of the vertices
  for (int i = 0; i < graph->vertexCount; i++) {
    if (graph->vertices[i] == v1)
      index1 = i;
    if (graph->vertices[i] == v2)
      index2 = i;
  }

  if (index1 != -1 && index2 != -1) {
    graph->matrix[index1][index2] = 0;
    graph->matrix[index2][index1] = 0; // For undirected graph
  } else {
    printf("One or both vertices not found!\n");
  }
}

void removeVertex(Graph *graph, int v) {
  int idx = -1;
  for (int i = 0; i < graph->vertexCount; i++) {
    if (graph->vertices[i] == v) {
      idx = i;
    }
  }
  if (idx == -1) {
    printf("Vertex is not exist!!!");
  }
  for (int i = 0; i < graph->vertexCount; i++) {
    for (int j = idx; j < graph->vertexCount; j++) {
      graph->matrix[i][j] = graph->matrix[i][j + 1];
      graph->matrix[j][i] = graph->matrix[j + 1][i];
    }
  }
  for (int i = idx; i < graph->vertexCount; i++) {
    graph->vertices[i] = graph->vertices[i + 1];
  }
  graph->vertexCount -= 1;
}

// Print the adjacency matrix
void printGraph(Graph *graph) {
  printf("   ");
  for (int i = 0; i < graph->vertexCount; i++) {
    printf("%d ", graph->vertices[i]);
  }
  printf("\n");

  for (int i = 0; i < graph->vertexCount; i++) {
    printf("%d: ", graph->vertices[i]);
    for (int j = 0; j < graph->vertexCount; j++) {
      printf("%d ", graph->matrix[i][j]);
    }
    printf("\n");
  }
}

// Main function to demonstrate the graph
int main() {
  Graph *graph = initializeGraph();

  // Add vertices
  addVertex(graph, 1);
  addVertex(graph, 5);
  addVertex(graph, 3);
  addVertex(graph, 6);
  addVertex(graph, 4);

  // Add edges
  addEdge(graph, 1, 5);
  addEdge(graph, 1, 3);
  addEdge(graph, 3, 5);
  addEdge(graph, 6, 3);
  addEdge(graph, 5, 4);

  // Print the adjacency matrix
  printf("Adjacency Matrix:\n");
  printGraph(graph);

  // Remove an edge
  /*printf("\nAfter removing edge (1, 3):\n");*/
  /*removeEdge(graph, 1, 3);*/
  /*printGraph(graph);*/

  printf("\nAfter removing vertex 4:\n");
  removeVertex(graph, 4);
  printf("Adjacency Matrix:\n");
  printGraph(graph);
  return 0;
}
