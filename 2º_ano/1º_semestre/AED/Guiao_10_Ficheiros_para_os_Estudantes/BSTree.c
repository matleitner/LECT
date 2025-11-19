//
// Algoritmos e Estruturas de Dados --- 2024/2025
//
// J Madeira, J M Rodrigues, Nov 2023
//
// Binary Search Tree storing pointers to items --- BALANCED TREE version
//

//// SEARCH ... AND COMPLETE ////

#include "BSTree.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct _BSTreeNode {
  void* item;
  struct _BSTreeNode* left;
  struct _BSTreeNode* right;
  int height;
};

struct _BSTreeHeader {
  unsigned int numNodes;
  struct _BSTreeNode* root;
  compFunc compare;
  printFunc print;
};

BSTree* BSTreeCreate(compFunc compF, printFunc printF) {
  BSTree* t = (BSTree*)malloc(sizeof(struct _BSTreeHeader));
  if (t == NULL) abort();

  t->numNodes = 0;
  t->root = NULL;
  t->compare = compF;
  t->print = printF;
  return t;
}

static void _treeDestroy(struct _BSTreeNode** pRoot) {
  struct _BSTreeNode* root = *pRoot;

  if (root == NULL) return;

  _treeDestroy(&(root->left));
  _treeDestroy(&(root->right));
  free(root);

  *pRoot = NULL;
}
// Q: What kind of tree traversal is this function doing?
// 1) Breadth-first,
// 2) Depth-first pre-order,
// 3) Depth-first in-order or
// 4) Depth-first post-order?
// A: 4) processa os nós filhos antes do pai
// Q: Is this the best order here? Why?
// A: Neste caso é a melhor solução, visto que necessita de libertar primeiro os filhos antes do pai

void BSTreeDestroy(BSTree** pHeader) {
  BSTree* header = *pHeader;
  if (header == NULL) return;

  _treeDestroy(&(header->root));

  free(header);

  *pHeader = NULL;
}

// GETTERS

int BSTreeIsEmpty(const BSTree* header) {
  assert(header != NULL);
  return header->root == NULL;
}

unsigned int BSTreeGetNumberOfNodes(const BSTree* header) {
  assert(header != NULL);
  return header->numNodes;
}

// Compute the height of the (sub-)tree whose root node is root.
// (Internal RECURSIVE function, that can be used for checking.)
static int _treeGetHeightREC(const struct _BSTreeNode* root) {
  // COMPLETE
  // leitner...
	if(root == NULL) // se a raiz não existe a altura tb n existe
	return -1;
	int left_height = _treeGetHeightREC(root->left);	//calcula a altura do ramo equerdo
	int right_height = _treeGetHeightREC(root->right); // calcula a altura do ramo direito 

	
  return 1 + ((left_height>right_height) ? left_height : right_height);
}

// Internal function that acccesses the height field, if the node exists
static int _treeGetHeight(const struct _BSTreeNode* root) {
  if (root == NULL) {
    return -1;
  }
  return root->height;
}

// Returns the tree height.
// An EMPTY TREE has height=-1
// and a tree with a single node has height=0.
int BSTreeGetHeight(const BSTree* header) {
  assert(header != NULL);
  return _treeGetHeight(header->root);
}

// Finds and returns the smallest item stored in the tree.
// Requires that the tree is not empty.
void* BSTreeGetMin(const BSTree* header) {
  assert(header != NULL);
  assert(!BSTreeIsEmpty(header));

  // COMPLETE the function with an ITERATIVE solution.
  // leitner...
	if(header == NULL)
  return NULL;
	struct _BSTreeNode* n = header->root;

	while(n->left != NULL){
		n = n->left;
	}
	return n->item;
}

// Finds and returns the largest item stored in the (sub-)tree rooted in the
// root node.
// (Înternal function called by BSTreeGetMax.)
static void* _treeGetMax(const struct _BSTreeNode* root) {
  assert(root != NULL);

  // COMPLETE the function with a RECURSIVE solution.
  // leitner...
	/*
	if (root->right == NULL)
		return _treeGetMax(root->right);
	return root->item;
	*/
	

	
	return (root->right == NULL ? root->item : _treeGetMax(root->right)); 
}

// Finds and returns the largest item stored in the tree.
// Requires that the tree is not empty.
void* BSTreeGetMax(const BSTree* header) {
  assert(header != NULL);
  assert(!BSTreeIsEmpty(header));

  return _treeGetMax(header->root);  // calls the internal recursive function
}

// Search a tree item.
// Returns a pointer to the item instance stored in the tree
// or NULL, if the item is not found.
void* BSTreeSearch(const BSTree* header, const void* item) {
  assert(header != NULL);
  assert(item != NULL);

  struct _BSTreeNode* current = header->root;
  compFunc compare = header->compare;
	while (current != NULL) {
    // COMPLETE THE LOOP.
    // leitner...
		if (compare(item, current->item) == 0) return current->item;
 	
		else if (compare(item, current->item) < 0 ){
			current = current->left;
		}
    
 		else{ 
      current = current->right;
    }
	}
		
  return NULL;
}

// Does the tree contain an element that compares==0 with this item?
int BSTreeContains(const BSTree* header, const void* item) {
  return BSTreeSearch(header, item) != NULL;
}

// Applies the function function to every tree item.
// (Internal function used in BSTreeTraverseINOrder.)
static void _treeTraverseINOrder(struct _BSTreeNode* root,
                                 void (*function)(void* p)) {
  // CORRECT THE FUNCTION SO THAT NODES ARE TRAVERSED IN INCREASING ORDER.
  // leitner...
  if (root == NULL) return;
  function(root->item);
  _treeTraverseINOrder(root->right, function);
  _treeTraverseINOrder(root->left, function);
}

// Applies the function function to every tree item.
void BSTreeTraverseINOrder(BSTree* header, void (*function)(void* p)) {
  assert(header != NULL);
  _treeTraverseINOrder(header->root, function);
}

//
// Internal functions the keep the TREE BALANCED
//

static void _updateNodeHeight(struct _BSTreeNode* t) {
  assert(t != NULL);

  int leftHeight = _treeGetHeight(t->left);
  int rightHeight = _treeGetHeight(t->right);

  t->height = 1 + (leftHeight >= rightHeight ? leftHeight : rightHeight);
}

static void _singleRotateWithLeftChild(struct _BSTreeNode** p) {
  struct _BSTreeNode* pLeft = (*p)->left;

  (*p)->left = pLeft->right;
  pLeft->right = *p;

  _updateNodeHeight(*p);
  _updateNodeHeight(pLeft);

  *p = pLeft;
}

static void _singleRotateWithRightChild(struct _BSTreeNode** p) {
  struct _BSTreeNode* pRight = (*p)->right;

  (*p)->right = pRight->left;
  pRight->left = *p;

  _updateNodeHeight(*p);
  _updateNodeHeight(pRight);

  *p = pRight;
}

static void _doubleRotateWithLeftChild(struct _BSTreeNode** p) {
  _singleRotateWithRightChild(&(*p)->left);
  _singleRotateWithLeftChild(p);
}

static void _doubleRotateWithRightChild(struct _BSTreeNode** p) {
  _singleRotateWithLeftChild(&(*p)->right);
  _singleRotateWithRightChild(p);
}

static void _balanceNode(struct _BSTreeNode** pRoot) {
  int leftHeight, rightHeight;

  if (*pRoot == NULL) return;
  leftHeight = _treeGetHeight((*pRoot)->left);
  rightHeight = _treeGetHeight((*pRoot)->right);

  if (leftHeight - rightHeight == 2) {
    leftHeight = _treeGetHeight((*pRoot)->left->left);
    rightHeight = _treeGetHeight((*pRoot)->left->right);
    if (leftHeight >= rightHeight)
      _singleRotateWithLeftChild(pRoot);
    else
      _doubleRotateWithLeftChild(pRoot);
  } else if (rightHeight - leftHeight == 2) {
    rightHeight = _treeGetHeight((*pRoot)->right->right);
    leftHeight = _treeGetHeight((*pRoot)->right->left);
    if (rightHeight >= leftHeight)
      _singleRotateWithRightChild(pRoot);
    else
      _doubleRotateWithRightChild(pRoot);
  } else
    (*pRoot)->height =
        1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Operations with items

// Internal recursive function

static int _BSTreeAdd(struct _BSTreeNode** pRoot, compFunc compF, void* item) {
  struct _BSTreeNode* root = *pRoot;

  if (root == NULL) {
    root = (struct _BSTreeNode*)malloc(sizeof(*root));
    if (root == NULL) abort();

    root->item = item;
    root->left = root->right = NULL;
    root->height = 0;

    *pRoot = root;
    return 1;
  }

  // Compare with current node
  int comp = compF(item, root->item);

  if (comp < 0) {
    // Try to insert on the left
    if (_BSTreeAdd(&(root->left), compF, item) == 0) {
      // No success
      return 0;
    }

    // Unbalanced on the left ?
    if (_treeGetHeight(root->left) - _treeGetHeight(root->right) == 2) {
      if (compF(item, root->left->item) < 0) {
        _singleRotateWithLeftChild(pRoot);
      } else {
        _doubleRotateWithLeftChild(pRoot);
      }
    }
    _updateNodeHeight(root);
    return 1;
  } else if (comp > 0) {
    // Try to insert on the right
    if (_BSTreeAdd(&(root->right), compF, item) == 0) {
      return 0;
    }

    // Unbalanced on the right ?
    if (_treeGetHeight(root->right) - _treeGetHeight(root->left) == 2) {
      if (compF(item, root->right->item) > 0) {
        _singleRotateWithRightChild(pRoot);
      } else {
        _doubleRotateWithRightChild(pRoot);
      }
    }
    _updateNodeHeight(root);
    return 1;
  } else {  // (comp == 0)
    // Not allowed
    return 0;
  }
}

// Adds an item to the tree.
// Returns 1 (success) if the item was added
// or 0 (fail) if the item collides with an already existing item.
int BSTreeAdd(BSTree* header, void* item) {
  assert(header != NULL);

  if (_BSTreeAdd(&(header->root), header->compare, item) == 1) {
    header->numNodes++;
    return 1;
  }
  return 0;
}

// Internal auxiliary function

static void _deleteNextNode(struct _BSTreeNode** pRoot, void** pItem) {
  if ((*pRoot)->left == NULL) {
    // FOUND IT
    struct _BSTreeNode* auxPointer = *pRoot;
    *pItem = auxPointer->item;
    *pRoot = auxPointer->right;
    free(auxPointer);
  } else {
    _deleteNextNode(&((*pRoot)->left), pItem);
    _updateNodeHeight(*pRoot);
  }
}

// This internal function removes the node pointed to by *pPointer.
// Note that pPointer is the address of a variable that points to the node to
// be removed. When it removes the node, it also sets that variable to NULL.
// That variable is either the root field of the _BSTreeHeader struct or
// the left or the right field of the parent _BSTreeNode struct.
// (Pointing to fields inside a struct is something you cannot do in Java.)
static void _removeNode(struct _BSTreeNode** pPointer) {
  struct _BSTreeNode* nodePointer = *pPointer;

  if ((nodePointer->left == NULL) && (nodePointer->right == NULL)) {
    /* A LEAF node */
    free(nodePointer);  // FREE it and
    *pPointer = NULL;   // SET field in parent node (or header) to NULL
  } else if (nodePointer->left == NULL) {
    /* It has only a RIGHT sub-tree */
    *pPointer = nodePointer->right;
    free(nodePointer);
  } else if (nodePointer->right == NULL) {
    /* It has only a LEFT sub-tree */
    *pPointer = nodePointer->left;
    free(nodePointer);
  } else {
    /* Node has TWO CHILDREN */
    /* Replace its item with the item of the next node in-order */
    /* And remove that node */
    _deleteNextNode(&(nodePointer->right), &(nodePointer->item));
  }
}

static int _treeRemoveItem(struct _BSTreeNode** pRoot, const void* item,
                           compFunc compare) {
  struct _BSTreeNode* root = *pRoot;

  if (root == NULL) {
    return 0;
  }
  int result;
  int cmp = compare(item, root->item);
  if (cmp < 0) {
    result = _treeRemoveItem(&(root->left), item, compare);
  } else if (cmp > 0) {
    result = _treeRemoveItem(&(root->right), item, compare);
  } else {  // (cmp == 0)
    _removeNode(pRoot);
    result = 1;
  }
  if (result) {
    _balanceNode(pRoot);  // Balance at this node
  }
  return result;
}

int BSTreeRemove(BSTree* header, const void* item) {
  assert(header != NULL);

  if (_treeRemoveItem(&(header->root), item, header->compare) == 1) {
    header->numNodes--;
    return 1;
  }
  return 0;
}

// Internal function required by BSTreeGetItems

// Traverses the tree recursively and adds the items to a QUEUE.
static void _BSTreeAddItems(const struct _BSTreeNode* p, Queue* q) {
  if (p == NULL) {
    return;
  }
  // COMPLETE
  // leitner...
	_BSTreeAddItems(p->left, q);
	QueueEnqueue(q, p->item);
	_BSTreeAddItems(p->right, q);
}	
// Q: What kind of tree traversal is this function doing?
// 1) Breadth-first,
// 2) Depth-first pre-order,
// 3) Depth-first in-order or <--- 
// 4) Depth-first post-order?
// A: 3)
// Q: Is this the required order here? Why?
// A: Neste caso é a travessia necessária, por se tratar de uma Binary Search Tree em
//     que deve devolver os elementos por ordem. 
// Returns a QUEUE with the ordered tree elements
// or an EMPTY QUEUE, if the tree is empty.
// The function ALLOCATES MEMORY for the QUEUE, that will have to be freed
// by the calling function.
Queue* BSTreeGetItems(const BSTree* header) {
  assert(header != NULL);

  Queue* itemsQ = QueueCreate();
  assert(itemsQ != NULL);
  _BSTreeAddItems(header->root, itemsQ);
  return itemsQ;
}

// Tree Visualization

static void _treeView(struct _BSTreeNode* root, int level, const char* edge,
                      printFunc print) {
  if (root == NULL) {
    printf("%*s%s\n", 4 * level, edge, "#");  // # represents NULL pointer
  } else {
    _treeView(root->left, level + 1, "/", print);
    printf("%*s[%d]", 4 * level, edge, root->height);
    print(root->item);
    printf("\n");
    _treeView(root->right, level + 1, "\\", print);
  }
}

void BSTreeView(const BSTree* header) {
  _treeView(header->root, 0, ":", header->print);  // : marks the root
  printf("numNodes: %d\n", header->numNodes);
}

//
// Tests - Auxiliary Functions
//

static unsigned int _BSTreeCountNodes(const struct _BSTreeNode* root) {
  if (root == NULL) {
    return 0;
  }
  return 1 + _BSTreeCountNodes(root->left) + _BSTreeCountNodes(root->right);
}

static int _BSTreeCheckNodesHeight(const struct _BSTreeNode* root) {
  if (root == NULL) {
    return 1;
  }
  if (_BSTreeCheckNodesHeight(root->left) == 0) {
    return 0;
  }
  if (_BSTreeCheckNodesHeight(root->right) == 0) {
    return 0;
  }
  return root->height == _treeGetHeightREC(root);
}

static int _BSTreeIsBalanced(const struct _BSTreeNode* root) {
  if (root == NULL) {
    return 1;
  }
  if (_BSTreeIsBalanced(root->left) == 0) {
    return 0;
  }
  if (_BSTreeIsBalanced(root->right) == 0) {
    return 0;
  }
  // Balancing factor at the root
  int F = _treeGetHeight(root->right) - _treeGetHeight(root->left);
  int ok = (-1 <= F && F <= 1);
  return ok;
}

int _isBST(struct _BSTreeNode* root, compFunc compF,
           struct _BSTreeNode** previous) {
  if (root == NULL) {
    return 1;
  }

  // IN_ORDER TRAVERSAL
  if (_isBST(root->left, compF, previous) == 0) {
    return 0;
  }

  // Allow only distinct valued nodes
  if (*previous != NULL && compF(root->item, (*previous)->item) <= 0) {
    return 0;
  }
  // Update previous to current
  *previous = root;

  return _isBST(root->right, compF, previous);
}

int BSTreeIsBST(const BSTree* header) {
  struct _BSTreeNode* p = NULL;
  return _isBST(header->root, header->compare, &p);
}

void BSTreeTestInvariants(const BSTree* header) {
  // check equivalence: numNodes==0 <=> root==NULL
  assert((header->numNodes == 0) == (header->root == NULL));
  // check equivalence: numNodes>0 <=> root!=NULL
  assert((header->numNodes > 0) == (header->root != NULL));
  // check equivalence: numNodes==0 <=> height = -1
  assert((header->numNodes == 0) == (BSTreeGetHeight(header) == -1));
  // check equivalence: numNodes==1 <=> height = 0
  assert((header->numNodes == 1) == (BSTreeGetHeight(header) == 0));
  // check equivalence: numNodes>1 <=> height > 0
  assert((header->numNodes > 1) == (BSTreeGetHeight(header) > 0));
  // Number of nodes ?
  assert(header->numNodes == _BSTreeCountNodes(header->root));
  // Height of each node ?
  assert((header->root == NULL) ||
         (_BSTreeCheckNodesHeight(header->root) == 1));
  // Is BST ?
  assert(BSTreeIsBST(header) == 1);
  // Is BALANCED ?
  assert(_BSTreeIsBalanced(header->root) == 1);
}
