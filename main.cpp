#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

// linked list node
struct Node {
  int data;
  Node *next;
  Node() : data(0), next(NULL) {}
  Node(int x, Node* next) : data(x), next(next) {}
};

// add new data
void push(struct Node **head, int new_data) {
  // allocate node
  Node* new_node = new Node();

  // put in the data
  new_node->data = new_data;

  // link the old list off the new node
  new_node->next = (*head);

  // move the head to pointer to the new node
  (*head) = new_node;
}

// delete duplicated nodes
Node* delete_duplicates(Node* head) {
  // sentinel
  Node* sentinel = new Node(0, head);

  // predecessor = the last node
  // before the sublist of duplicates
  Node* pred = sentinel;

  while (head != NULL) {
    // if it's beginning of duplicates sublist
    // skip all duplicates
    if (head->next != NULL && head->data == head->next->data) {
      // move till the end of duplicates sublist
      while (head->next != NULL && head->data == head->next->data) {
        head = head->next;
      }
      // skip all duplicates
      pred->next = head->next;
    }
    else { // otherwise, move predecessor
      pred = pred->next;
    }
    
    // move forward
    head = head->next;
  }

  return sentinel->next;
}

// main process
int main(void) {
  // start with the empty list
  Node* head = NULL;

  // create sorted linked list
  // sorted in ascending order
  push(&head, 5);
  push(&head, 4);
  push(&head, 3);
  push(&head, 3);
  push(&head, 2);
  push(&head, 2);
  push(&head, 1);

  Node* result = delete_duplicates(head);

  // print data of each node
  while (result != NULL)
  {
    cout << result->data << endl;
    result = result->next;
  }
  
  return 0;
}