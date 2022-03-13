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

Node* add_two_numbers(Node* l1, Node* l2) {
  Node* dummy_head = new Node(0);

  Node* p = l1;
  Node* q = l2;
  Node* current = dummy_head;

  int carry = 0;

  while (p != NULL || q != NULL) {
    int x = 0;
    if (p != NULL) x = p->data;

    int y = 0;
    if (q != NULL) y = q->data;

    int sum = x + y + carry;
    carry = sum / 10;

    current->next = new Node(sum % 10);
    current = current->next;

    if (p != NULL) p = p->next;
    if (q != NULL) q = q->next;
  }

  // end of list
  if (carry > 0) current->next = new Node(carry);

  return dummy_head->next;
}

int main(void) {
  // create input linked list: l1
  Node* l1 = NULL;
  push(&l1, 3);
  push(&l1, 4);
  push(&l1, 2);

  // create input linked list: l2
  Node* l2 = NULL;
  push(&l2, 4);
  push(&l2, 6);
  push(&l2, 5);

  Node* result = add_two_numbers(l1, l2);

  // print data of each node
  while (result != NULL)
  {
    cout << result->data << endl;
    result = result->next;
  }
  
  return 0;
}