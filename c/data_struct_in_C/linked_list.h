#include <stdlib.h>

typedef struct LLNode{
  int val;
  struct LLNode *next;
} LLNode;

LLNode *newListNode(int head_val);
void print_ll(LLNode *head);
int find_node(LLNode *head, int val);
void insert_node(LLNode *pos_node, LLNode *new_node);
int remove_node(LLNode *head, LLNode *del_node);
