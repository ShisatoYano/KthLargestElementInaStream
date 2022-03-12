#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

// linked list node
struct Node {
  int data;
  struct Node *next;
};

// add new data
void push(struct Node **head, int new_data) {
  // allocate node
  struct Node *new_node = new Node;

  // put in the data
  new_node->data = new_data;

  // link the old list off the new node
  new_node->next = (*head);

  // move the head to pointer to the new node
  (*head) = new_node;
}

// delete duplicated nodes
Node* delete_duplicates(Node* head) {
  Node* current = head;

  while (current != NULL && current->next != NULL) {
    if (current->next->data == current->data) {
      current->next = current->next->next;
    }
    else {
      current = current->next;
    }
  }

  return head;
}

// main process
int main(void) {
  // start with the empty list
  Node* head = NULL;

  // create sorted linked list
  // sorted in ascending order
  push(&head, 1);
  push(&head, 1);
  push(&head, 1);
  push(&head, 2);
  push(&head, 2);
  push(&head, 3);
  push(&head, 3);
  push(&head, 3);

  Node* result = NULL;
  result = delete_duplicates(head);

  // print data of each node
  Node* current = result; 
  while (current != NULL)
  {
    cout << current->data << endl;
    current = current->next;
  }
  
  return 0;
}