//
// Algoritmos e Estruturas de Dados --- 2024/2025
//
// Joaquim Madeira, November 2023, November 2024
//
// Integers Binary Tree ---SECOND VERSION --- Test Code
//
// SOME FUNCTIONS ARE INCOMPLETE on IntegersBinTree.c
//

#include <stdio.h>
#include <stdlib.h>

#include "IntegersBinTree.h"

// Functions will operate on the integer value stored on a tree node
// And that will be passed to the traversal functions

void printInteger(int* p) { printf("%d ", *p); }

void multiplyIntegerBy2(int* p) { *p *= 2; }

int main(void) {
  // Just for testing purposes
  Tree* tree = createExampleTree();

  printf("Created an example tree\n");

  if (TreeIsEmpty(tree)) {
    printf("The created tree is EMPTY --- Something is WRONG !!\n");
  } else {
    printf("The created tree is OK\n");
  }

  printf("Number of nodes = %d\n", TreeGetNumberOfNodes(tree));

  printf("Height = %d\n", TreeGetHeight(tree));

  printf("SMALLEST value = %d\n", TreeGetMin(tree));

  printf("LARGEST value = %d\n", TreeGetMax(tree));

  // The recursive tree traversals
  // are used to print the integer values stored in the tree

  printf("PRE-Order traversal : ");

  TreeTraverseInPREOrder(tree, printInteger);

  printf("\n");

  printf("IN-Order traversal : ");

  TreeTraverseINOrder(tree, printInteger);

  printf("\n");

  printf("POST-Order traversal : ");

  TreeTraverseInPOSTOrder(tree, printInteger);

  printf("\n");

  printf("LEVEL-by-LEVEL traversal using a QUEUE: ");

  TreeTraverseLevelByLevelWithQUEUE(tree, printInteger);

  printf("\n");

  printf("PRE-Order traversal using a STACK : ");

  TreeTraverseInPREOrderWithSTACK(tree, printInteger);

  printf("\n");

  printf("IN-Order traversal using a STACK: ");

  TreeTraverseINOrderWithSTACK(tree, printInteger);

  printf("\n");

  // Checking if integer values belong to the tree

  for (int i = 0; i < 16; i++) {
    if (TreeContains(tree, i)) {
      printf("The tree contains %d\n", i);
    } else {
      printf("The tree DOES NOT CONTAIN %d\n", i);
    }
  }

  // Using a tree traversal to multiply the value of each node
  // Easy to do in this way !

  printf("Multiply each value by 2\n");

  TreeTraverseInPREOrder(tree, multiplyIntegerBy2);

  printf("PRE-Order traversal : ");

  TreeTraverseInPREOrder(tree, printInteger);

  printf("\n");

  // Checking if two trees are equal

  if (TreeEquals(tree, tree)) {
    printf("The tree EQUALS ITSELF\n");
  } else {
    printf("Something WRONG happened!!\n");
  }

  // Checkiing if two trees are mirrored trees

  if (TreeMirrors(tree, tree)) {
    printf("Something WRONG happened!!\n");
  } else {
    printf("The tree DOES NOT MIRROR ITSELF\n");
  }

  printf("STORING in a file\n");

  TreeStoreInFile(tree, "arvore1.txt", 1);

  printf("READING from a file\n");

  Tree* treeFromFile = TreeGetFromFile("arvore1.txt", 1);

  printf("FINISHED READING from a file\n");

  if (TreeEquals(tree, treeFromFile)) {
    printf("The tree EQUALS the one read from file\n");
  } else {
    printf("Something WRONG happened!!\n");
  }

  // Deleting all nodes of a tree

  TreeDestroy(&tree);

  printf("The tree was DESTROYED\n");

  // After that, the tree should be empty

  if (TreeIsEmpty(tree)) {
    printf("The tree is NOW EMPTY\n");
  } else {
    printf("Something WRONG happened!!\n");
  }

  return 0;
}
