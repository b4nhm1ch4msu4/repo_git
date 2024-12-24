#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define QUEUE_CAP 10

typedef struct TreeNode {
  int value;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

typedef struct QueueNode {
  TreeNode *node;
  struct QueueNode *next;
} QueueNode;

typedef struct Queue {
  QueueNode *head;
  QueueNode *tail;
  int size;
} Queue;

// Queue function
QueueNode *new_node(TreeNode *new_node);
Queue *queue_init();
void queue_push(Queue *my_queue, TreeNode *node);
TreeNode *queue_pop(Queue *my_queue);
int queue_isempty(Queue *my_queue);

// Tree function
TreeNode *newTreeNode(int value);
void level_order_traversal(TreeNode *root);
void preOrder(TreeNode *root);
void inOrder(TreeNode *root);
void postOrder(TreeNode *root);

QueueNode *new_node(TreeNode *new_node) {
  QueueNode *node = malloc(sizeof(QueueNode));
  node->node = new_node;
  node->next = NULL;
  return node;
}

Queue *queue_init() {
  Queue *my_queue = malloc(sizeof(Queue));
  my_queue->size = 0;
  my_queue->head = NULL;
  my_queue->tail = NULL;
  return my_queue;
}

int queue_isempty(Queue *my_queue) {
  if (my_queue->size == 0) {
    return TRUE;
  }
  return FALSE;
}

void queue_push(Queue *my_queue, TreeNode *node) {
  QueueNode *queue_node = new_node(node);
  if (queue_isempty(my_queue) == TRUE) {
    my_queue->head = queue_node;
    my_queue->tail = queue_node;
  } else {
    my_queue->tail->next = queue_node;
    my_queue->tail = queue_node;
  }
  my_queue->size++;
}

TreeNode *queue_pop(Queue *my_queue) {
  if (queue_isempty(my_queue) == TRUE) {
    return NULL;
  }
  QueueNode *node = my_queue->head;
  my_queue->head = node->next;
  my_queue->size--;
  return node->node;
}

TreeNode *newTreeNode(int value) {
  TreeNode *newNode = calloc(1, sizeof(TreeNode));
  newNode->value = value;
  return newNode;
}

void level_order_traversal(TreeNode *root) {
  Queue *queue = queue_init();
  queue_push(queue, root);
  while (queue_isempty(queue) == FALSE) {
    TreeNode *cur = queue_pop(queue);
    printf("%d ", cur->value);
    if (cur->left != NULL) {
      queue_push(queue, cur->left);
    }
    if (cur->right != NULL) {
      queue_push(queue, cur->right);
    }
  }
}
void preOrder(TreeNode *root){
  if (root == NULL) {
    return;
  }
  printf("%d ", root->value);
  preOrder(root->left);
  preOrder(root->right);
}

void inOrder(TreeNode *root){
  if (root == NULL) {
    return;
  }
  inOrder(root->left);
  printf("%d ",root->value);
  inOrder(root->right);
}

void postOrder(TreeNode *root){
  if (root == NULL) {
    return;
  }
  postOrder(root->left);
  postOrder(root->right);
  printf("%d ", root->value);

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

  printf("level order: ");
  level_order_traversal(n1);
  printf("\npre Order: ");
  preOrder(n1);
  printf("\nin Order: ");
  inOrder(n1);
  printf("\npost Order: ");
  postOrder(n1);

  free(n1);
  free(n2);
  free(n3);
  free(n4);
  free(n5);
  free(n0);

  return EXIT_SUCCESS;
}
