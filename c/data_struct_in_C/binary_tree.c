#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
  int value;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

typedef struct Queue {
  int head;
  int tail;
  TreeNode *container;
} Queue;

Queue *queue_init();
void queue_push(Queue *my_queue, TreeNode *node);
TreeNode *queue_pop(Queue *my_queue);
int queue_isempty(Queue *my_queue);

Queue *queue_init() {
  Queue *my_queue = calloc(1, sizeof(Queue));
  my_queue->head = 0;
  my_queue->tail = 0;
  TreeNode *container = calloc(10, sizeof(TreeNode));
  my_queue->container = container;
  return my_queue;
}

int queue_isempty(Queue *my_queue) {
  int head_idx = my_queue->head % 10;
  int tail_idx = my_queue->tail % 10;
  if (head_idx - tail_idx < 0) {
    return TRUE;
  } else {
    return FALSE;
  }
}

void queue_push(Queue *my_queue, TreeNode *node) {
  my_queue->tail++;
  int index = my_queue->tail % 10;
  my_queue->container[index] = *node;
}

TreeNode *queue_pop(Queue *my_queue) {
  if (queue_isempty(my_queue) == TRUE) {
    return NULL;
  }
  TreeNode *head = my_queue->container[my_queue->head % 10];
  my_queue->head++;
  return head;
}

TreeNode *newTreeNode(int value);
void level_order_traversal(TreeNode *root);

TreeNode *newTreeNode(int value) {
  TreeNode *newNode = calloc(1, sizeof(TreeNode));
  newNode->value = value;
  return newNode;
}

void level_order_traversal(TreeNode *root) {
  Queue *my_queue = queue_init();
  queue_push(my_queue, root);
  while (queue_isempty(my_queue) == FALSE) {
    TreeNode *node = queue_pop(my_queue);
    printf("%d ", node->value);
    if (node->left != NULL) {
      queue_push(my_queue, node->left);
    }

    if (node->right != NULL) {
      queue_push(my_queue, node->right);
    }
  }
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

  Queue *my_queue = queue_init();
  queue_push(my_queue, n1);
  for(int i = 0 ; i < 10; i++){
    printf("%d ", my_queue->container[i]->value);
  }

  /*level_order_traversal(n1);*/

  free(n1);
  free(n2);
  free(n3);
  free(n4);
  free(n5);
  free(n0);

  return EXIT_SUCCESS;
}
