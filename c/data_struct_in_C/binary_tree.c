#include "queue.c"
#include <stdlib.h>
typedef struct TreeNode {
  int value;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

TreeNode *newTreeNode(int value);
void level_order_traversal(TreeNode *root);




TreeNode *newTreeNode(int value) {
  TreeNode *newNode = calloc(1, sizeof(TreeNode));
  newNode->value = value;
  return newNode;
}

void level_order_traversal(TreeNode *root){
   
}

int main(int argc, char *argv[]) {
  TreeNode *n1 = newTreeNode(1);
  TreeNode *n2 = newTreeNode(2);
  TreeNode *n3 = newTreeNode(3);
  TreeNode *n4 = newTreeNode(4);
  TreeNode *n5 = newTreeNode(5);

  n1->left = n2;
  n1->right = n3;
  n2->left = n4;
  n2->right = n5;
  // insert a new TreeNode
  TreeNode *n0 = newTreeNode(0);
  n1->left = n0;
  n0->left = n2;

  // remove a TreeNode
  n1->left = n2;
  n0->left = NULL;

  free(n1);
  free(n2);
  free(n3);
  free(n4);
  free(n5);
  free(n0);

  return EXIT_SUCCESS;
}
