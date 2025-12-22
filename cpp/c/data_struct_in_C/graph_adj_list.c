#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10 // Maximum number of vertices

// Node in the adjacency list
typedef struct Node {
  int vertex;
  struct Node *next;
} Node;

// Graph structure
typedef struct Graph {
  int numVertices;
  Node *adjLists[MAX_VERTICES]; // Array of adjacency lists
} Graph;

// Function to create a new node
Node *createNode(int vertex) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->vertex = vertex;
  newNode->next = NULL;
  return newNode;
}

// Function to create a graph with n vertices
Graph *createGraph() {
  Graph *graph = (Graph *)malloc(sizeof(Graph));
  graph->numVertices = 0;

  // Initialize each adjacency list as empty
  for (int i = 0; i < MAX_VERTICES; i++) {
    graph->adjLists[i] = NULL;
  }

  return graph;
}

// Add an edge to the graph
void addEdge(Graph *graph, int src, int dest) {
  int idx_src = -1;
  int idx_dest = -1;
  for (int i = 0; i < graph->numVertices; i++) {
    Node *head = graph->adjLists[i];
    if (head->vertex == src) {
      idx_src = i;
    }
    if (head->vertex == dest) {
      idx_dest = i;
    }
  }

  if (idx_dest == -1 || idx_src == -1) {
    printf("invalid Vertex value \n");
    return;
  }

  // Add an edge from src to dest
  Node *newNode = createNode(dest);
  newNode->next = graph->adjLists[idx_src]->next;
  graph->adjLists[idx_src]->next = newNode;

  // Add an edge from dest to src (undirected graph)
  newNode = createNode(src);
  newNode->next = graph->adjLists[idx_dest]->next;
  graph->adjLists[idx_dest]->next = newNode;
}

void addVertex(Graph *graph, int vertex) {
  Node *newNode = createNode(vertex);
  graph->adjLists[graph->numVertices] = newNode;
  graph->numVertices++;
}
void removeEdge(Graph *graph, int src, int dest) {
  printf("remove edge -> src : %d, dest : %d\n", src, dest);
  int idx_src = -1;
  int idx_dest = -1;
  for (int i = 0; i < graph->numVertices; i++) {
    Node *head = graph->adjLists[i];
    if (head->vertex == src) {
      idx_src = i;
    }
    if (head->vertex == dest) {
      idx_dest = i;
    }
  }
  Node *cur = graph->adjLists[idx_src];
  Node *next = cur->next;
  while (next != NULL) {
    if (next->vertex == dest) {
      cur->next = next->next;
      free(next);
      break;
    }
    cur = cur->next;
    next = cur->next;
  }
  cur = graph->adjLists[idx_dest];
  next = cur->next;
  while (next != NULL) {
    if (next->vertex == src) {
      cur->next = next->next;
      free(next);
      break;
    }
    cur = cur->next;
    next = cur->next;
  }
}

void removeVertex(Graph *graph, int vertex) {
  int idx = -1;
  for (int i = 0; i < graph->numVertices; i++) {
    if (graph->adjLists[i]->vertex == vertex) {
      idx = i;
    }
  }
  Node *src = graph->adjLists[idx];
  Node *dest = graph->adjLists[idx]->next;
  while (dest) {
    removeEdge(graph, src->vertex, dest->vertex);
    dest = graph->adjLists[idx]->next;
  }
  for (int i = idx; i < graph->numVertices; i++) {
    graph->adjLists[i] = graph->adjLists[i + 1];
  }
  graph->numVertices--;
}

// Print the graph
void printGraph(Graph *graph) {
  printf("Vertex count: %d\n", graph->numVertices);
  for (int i = 0; i < graph->numVertices; i++) {
    Node *temp = graph->adjLists[i];
    printf("Vertex %d: ", i);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("NULL\n");
  }
}

// Free memory allocated for the graph
/*void freeGraph(Graph *graph) {*/
/*  for (int i = 0; i < graph->numVertices; i++) {*/
/*    Node *temp = graph->adjLists[i];*/
/*    while (temp) {*/
/*      Node *toFree = temp;*/
/*      temp = temp->next;*/
/*      free(toFree);*/
/*    }*/
/*    free(graph->adjLists[i]);*/
/*  }*/
/*  free(graph);*/
/*}*/

// Main function to demonstrate the graph
int main() {
  // Create a graph with 5 vertices
  Graph *graph = createGraph();
  addVertex(graph, 1);
  addVertex(graph, 3);
  addVertex(graph, 4);
  addVertex(graph, 5);
  addVertex(graph, 6);

  // Add edges
  addEdge(graph, 1, 3);
  addEdge(graph, 5, 4);
  addEdge(graph, 5, 3);
  addEdge(graph, 6, 3);

  // Print the adjacency list representation of the graph
  printf("Adjacency List of the Graph:\n");
  printGraph(graph);

  /*printf("remove edge 1-3\n");*/
  /*removeEdge(graph, 1, 3);*/
  /*removeEdge(graph, 5, 4);*/
  /*removeEdge(graph, 5, 3);*/
  /*removeEdge(graph, 6, 3);*/
  /*printGraph(graph);*/

  printf("remove vertext 5\n");
  removeVertex(graph, 5);
  printGraph(graph);
  // Free the memory used by the graph
  /*freeGraph(graph);*/

  return 0;
}
