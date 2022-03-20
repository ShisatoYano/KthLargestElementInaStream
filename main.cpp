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

Node* reverse_list_recursive(Node* head) {
  if (head == NULL || head->next == NULL) return head;

  Node* p = reverse_list_recursive(head->next);

  head->next->next = head;

  head->next = NULL;

  return p;
}

int main(void) {
  cout << "Iterative Approach" << endl;
  cout << "Input LinkedList: 1->2->3->4->5" << endl;
  
  Node* head1 = NULL;
  push(&head1, 5);
  push(&head1, 4);
  push(&head1, 3);
  push(&head1, 2);
  push(&head1, 1);

  Node* result_iterative = reverse_list_iterative(head1);
  while (result_iterative != NULL)
  {
    cout << result_iterative->data << "->";
    result_iterative = result_iterative->next;
  }
  cout << "" << endl;
  
  cout << "Recursive Approach" << endl;
  cout << "Input LinkedList: 1->2->3->4->5" << endl;

  Node* head2 = NULL;
  push(&head2, 5);
  push(&head2, 4);
  push(&head2, 3);
  push(&head2, 2);
  push(&head2, 1);

  Node* result_recursive = reverse_list_recursive(head2);
  while (result_recursive != NULL)
  {
    cout << result_recursive->data << "->";
    result_recursive = result_recursive->next;
  }
  cout << "" << endl;
  
  return 0;
}