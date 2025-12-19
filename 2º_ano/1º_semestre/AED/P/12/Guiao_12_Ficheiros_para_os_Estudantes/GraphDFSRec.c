//
// Algoritmos e Estruturas de Dados --- 2024/2025
//
// Joaquim Madeira, Joao Manuel Rodrigues - May 2020, Nov 2024
//
// GraphDFS - RECURSIVE Depth-First Search
//

#include "GraphDFSRec.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "IntegersStack.h"

struct _GraphDFSRec {
  unsigned int* marked;  // Mark with 1 the first time a vertex is reached
  int* predecessor;      // The correponding predecessor vertex
  Graph* graph;
  unsigned int startVertex;  // The start vertex for the traversal
};

// The (internal) recursive function for the traversal
static void _dfs(GraphDFSRec* traversal, unsigned int vertex) {
  // Mark the start vertex as visited
  traversal->marked[vertex] = 1;

  // Get the array of adjacent vertices
  // neighbors[0] stores the number of neighbors
  unsigned int* neighbors = GraphGetAdjacentsTo(traversal->graph, vertex);

  // Iterate through the adjacent vertices
  for (unsigned int i = 1; i <= neighbors[0]; i++) {
    unsigned int w = neighbors[i];
    // Check if already visited
    if (traversal->marked[w] == 0) {
      traversal->predecessor[w] = vertex;
      _dfs(traversal, w);
    }
  }

  // Free the created neighbors array
  free(neighbors);
}

// Function to execute the DFS traversal
// It encapsulates the recursive function
// And allocates memory storing the result of the traversal
GraphDFSRec* GraphDFSRecExecute(Graph* g, unsigned int startVertex) {
  assert(g != NULL);
  assert(startVertex < GraphGetNumVertices(g));

  GraphDFSRec* result = (GraphDFSRec*)malloc(sizeof(struct _GraphDFSRec));
  assert(result != NULL);

  unsigned int numVertices = GraphGetNumVertices(g);

  // Mark all vertices as not yet visited
  result->marked = (unsigned int*)calloc(numVertices, sizeof(unsigned int));
  assert(result->marked != NULL);

  // No vertex has (yet) a (valid) predecessor
  result->predecessor = (int*)malloc(numVertices * sizeof(int));
  assert(result->predecessor != NULL);
  for (unsigned int i = 0; i < numVertices; i++) {
    result->predecessor[i] = -1;
  }

  result->graph = g;
  result->startVertex = startVertex;

  // START THE RECURSIVE TRAVERSAL
  _dfs(result, startVertex);

  return result;
}

void GraphDFSRecDestroy(GraphDFSRec** p) {
  assert(*p != NULL);

  GraphDFSRec* aux = *p;

  free(aux->marked);
  free(aux->predecessor);

  free(*p);
  *p = NULL;
}

// Getting the result

unsigned int GraphDFSRecHasPathTo(const GraphDFSRec* p, unsigned int v) {
  assert(p != NULL);
  assert(v < GraphGetNumVertices(p->graph));

  return p->marked[v];
}

Stack* GraphDFSRecPathTo(const GraphDFSRec* p, unsigned int v) {
  assert(p != NULL);
  assert(v < GraphGetNumVertices(p->graph));

  Stack* s = StackCreate(GraphGetNumVertices(p->graph));

  if (p->marked[v] == 0) {
    return s;
  }

  // Store the path
  for (unsigned int current = v; current != p->startVertex;
       current = p->predecessor[current]) {
    StackPush(s, current);
  }

  StackPush(s, p->startVertex);

  return s;
}

// DISPLAYING on the console

void GraphDFSRecShowPath(const GraphDFSRec* p, unsigned int v) {
  assert(p != NULL);
  assert(v < GraphGetNumVertices(p->graph));

  Stack* s = GraphDFSRecPathTo(p, v);

  while (StackIsEmpty(s) == 0) {
    printf("%d ", StackPop(s));
  }

  StackDestroy(&s);
}

void GraphDFSRecDisplay(const GraphDFSRec* p) {
  assert(p != NULL);

  // TO BE COMPLETED !!
}

// NEW --- Display the Paths-Tree in DOT format
void GraphDFSRecDisplayDOT(const GraphDFSRec* p) {
  assert(p != NULL);

  Graph* original_graph = p->graph;
  unsigned int num_vertices = GraphGetNumVertices(original_graph);

  // The paths tree is a digraph, with no edge weights
  Graph* paths_tree = GraphCreate(num_vertices, 1, 0);

  // Use the predecessors array to add the tree edges
  for (unsigned int w = 0; w < num_vertices; w++) {
    // Vertex w has a predecessor vertex v?
    int v = p->predecessor[w];
    if (v != -1) {
      GraphAddEdge(paths_tree, (unsigned int)v, w);
    }
  }

  // Display the tree in the DOT format
  GraphDisplayDOT(paths_tree);

  // Housekeeping
  GraphDestroy(&paths_tree);
}
