#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
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

void print_ll(LLNode *my_ll) {
  LLNode *cur = my_ll;
  do {
    printf("%d ", cur->val);
    cur = cur->next;
  } while (cur != NULL);
  printf("\n");
}

LLNode *newLLNode(int head_val) {
  LLNode *node;
  node = (LLNode *)malloc(sizeof(LLNode));
  node->val = head_val;
  node->next = NULL;
  return node;
}

int find_node(LLNode *head, int val) {
  LLNode *cur = head;
  int index = 0;
  do {
    if (cur->val == val) {
      printf("found val %d in linked list at index %d.", val, index);
      return index;
    }
    cur = cur->next;
    index++;
  } while (cur != NULL);
  return -1;
}

void insert_node(LLNode *pos_node, LLNode *new_node) {
  new_node->next = pos_node->next;
  pos_node->next = new_node;
}

int remove_node(LLNode *head, LLNode *del_node) {
  LLNode *cur_node = head;
  do {
    if (cur_node->next == del_node) {
      cur_node->next = del_node->next;
      del_node->next = NULL;
      free(del_node);
      return 0;
    }
    cur_node = cur_node->next;
  } while (cur_node != NULL);

  printf("Node %d is not in this linked list.\n",del_node->val);
  return -1;

}

/////////////////////////////
///// MAIN ENTRY POINT /////
////////////////////////////
int main(int argc, char *argv[]) {
  LLNode *n0 = newLLNode(0);
  LLNode *n1 = newLLNode(1);
  LLNode *n2 = newLLNode(2);
  LLNode *n3 = newLLNode(3);
  LLNode *n5 = newLLNode(5);

  print_ll(n0);

  insert_node(n0, n1);
  insert_node(n1, n2);
  insert_node(n2, n3);
  print_ll(n0);
printf("remove node n2.\n");
  remove_node(n0, n2);
  print_ll(n0);

printf("remove node n5.\n");
  remove_node(n0, n5);
  print_ll(n0);
  return 0;
}
