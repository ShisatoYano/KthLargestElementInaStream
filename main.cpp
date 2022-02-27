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

// return true if there is a cycle in linked list
bool detect_cycle(struct Node *head) {
  unordered_set<Node *> nodes;

  while (head != NULL) {
    // this node is already present
    if (nodes.find(head) != nodes.end()) return true;

    // see the node for the first time
    nodes.insert(head);

    head = head->next;
  }

  return false;
}

// main process
int main(void) {
  // start with the empty list
  struct Node *head = NULL;

  push(&head, 20);
  push(&head, 4);
  push(&head, 15);
  push(&head, 10);

  // create a cycle
  head->next->next->next->next = head;

  if (detect_cycle(head)) cout << "Cycle found" << endl;
  else cout << "No cycle" << endl;

  return 0;
}