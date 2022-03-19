#include <iostream>
#include <string>

using namespace std;

struct Node {
  int data;
  Node *next;
  Node() : data(0), next(NULL) {}
  Node(int x) : data(x), next(NULL) {}
  Node(int x, Node* next) : data(x), next(next) {}
};

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

Node* reverse_list_iterative(Node* head) {
  Node* prev = NULL;
  Node* curr = head;

  while (curr != NULL) {
    Node* next_temp = curr->next;

    curr->next = prev;

    prev = curr;

    curr = next_temp;
  }

  return prev;
}

int main(void) {
  // create input 
  Node* head = NULL;
  push(&head, 5);
  push(&head, 4);
  push(&head, 3);
  push(&head, 2);
  push(&head, 1);

  Node* result_iterative = reverse_list_iterative(head);

  cout << "Result by Iterative Approach" << endl;
  while (result_iterative != NULL)
  {
    cout << result_iterative->data << endl;
    result_iterative = result_iterative->next;
  }
  
  return 0;
}