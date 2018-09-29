#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

void printList(struct Node *n) {
  while(n != NULL) {
    printf("\n%d\n",n->data);
    n = n->next;
  }
  return;
}

void push(struct Node** head_ref, int data) {
  /* *pi refers to the integer in location of &x if pi=&x */
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = *head_ref;
  *head_ref = new_node;
  return;
}

void insertAfter(struct Node* prev, int data) {
  if(prev == NULL) {
    printf("previous node cannot be null");
    return;
  }
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = prev->next;
  prev->next = new_node;
  return;
}

void append(struct Node** head_ref, int data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node* last = *head_ref;
  new_node->data = data;
  new_node->next = NULL;

  if(*head_ref = NULL) {
    *head_ref = new_node;
    return;
  }

  while(last->next) {
    last = last->next;
  }

  last->next = new_node;
  return;

}

void deleteNode (struct Node** head_ref, int key) {
  struct Node* temp = *head_ref, *prev;

  if(temp !=NULL && temp->data == key) {
    *head_ref = temp->next;
    free(temp);
    return;
  }

  while(temp != NULL && temp->data == key){
    prev = temp;
    temp = temp->next;
  }

  if(temp == NULL) return;

  prev->next = temp->next;
  free(temp);
  return;
}

void deleteByIndex(struct Node** head_ref, int key) {

}

int main() {
  struct Node segErr;
  /* Start with the empty list */
 struct Node* head = &segErr;

 // Insert 6.  So linked list becomes 6->NULL
//  append(&head, 6);

 // Insert 7 at the beginning. So linked list becomes 7->6->NULL
 push(&head, 7);

 // Insert 1 at the beginning. So linked list becomes 1->7->6->NULL
 push(&head, 1);

 // Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
//  append(&head, 4);

 // Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL
 insertAfter(head->next, 8);

//  printList(head);

//  deleteNode(&head, 1);

 printf("\n Created Linked list is: ");
 printList(head);
  return 0;
}
