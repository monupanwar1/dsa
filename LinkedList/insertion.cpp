
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int node;
  Node *next;

public:
  Node(int node)
  {
    this->node = node;
    this->next = nullptr;
  };

public:
  Node(int node, Node *next)
  {
    this->node = node;
    this->next = next;
  };
};

// array to linked list

Node *arrayToLinkedList(vector<int> &arr)
{
  int n = arr.size();

  Node *head = new Node(arr[0]);
  Node *temp = head;

  for (int i = 1; i < n; i++)
  {
    temp->next = new Node(arr[i]);
    temp = temp->next;
  }

  return head;
}

void print(Node *head)
{
  Node *temp = head;

  while (temp != nullptr)
  {
    cout << temp->node << "  ";
    temp = temp->next;
  }
  cout << endl;
}

Node *insertAtHead(Node *head, int val)
{

  Node *newNode = new Node(val, head);
  return newNode;
}

Node *insertAtTail(Node *head, int val)
{
  Node *temp = head;
  Node *newNode = new Node(val);

  while (temp->next != nullptr)
  {
    temp = temp->next;
  }
  temp->next = newNode;

  return head;
}

Node *insertAtK(Node *head, int val, int k)
{
  if (head == nullptr)
  {
    if (k == 1)
    {
      Node *newNode = new Node(val, head);
      return newNode;
    }
  }

  if (k == 1)
  {
    Node *newNode = new Node(val, head);
    return newNode;
  }

  Node *temp = head;
  int count = 0;

  while (temp->next != nullptr)
  {
    if (count == k - 1)
    {
      Node *newNode = new Node(val, head);
      newNode->next = temp->next;
      temp->next = newNode;
    }
    temp = temp->next;
    count++;
  }

  return head;
}

Node *insertBeforeK(Node *head, int val, int target)
{

  if (head == nullptr)
  {
    return nullptr;
  }

  if (head->node == target)
  {
    Node *newNode = new Node(val, head);
    return newNode;
  }

  Node *temp = head;

  while (temp->next != nullptr)
  {
    if (temp->next->node == target)
    {
      Node *newNode = new Node(val, temp->next);
      temp->next = newNode;
      break;
    }
    temp = temp->next;
  }

  return head;
}

Node *insertAtK2(Node *head, int val, int elem)
{
  if (head == nullptr)
  {
    return nullptr;
  }

  if (head->node == elem)
  {
    Node *newNode = new Node(val, head);
    return newNode;
  }

  Node *temp = head;
  int count = 0;

  while (temp->next != nullptr)
  {
    if (temp->next->node == elem)
    {
      Node *newNode = new Node(val, temp->next);
      temp->next = newNode;
      break;
    }
    temp = temp->next;
  }

  return head;
}

int main()
{
  vector<int> arr = {10, 20, 30};

  Node *head = arrayToLinkedList(arr);

  // head = insertAtHead(head, 100);
  // print(head);
  // head = insertAtTail(head, 100);
  // print(head);

  // head = insertAtK(head, 0, 1);
  // print(head);

  // head = insertAtK(head, 25, 3);
  // print(head);

  // head = insertAtK(head, 15, 2);
  // print(head);

  // head = insertBeforeK(head, 0, 10);
  // print(head);

  // head = insertBeforeK(head, 25, 30);
  // print(head);

  // head = insertAtK2(head, 15, 10);
  // print(head);

  head = insertAtK2(head, 35, 40);
  print(head);

  head = insertAtK2(head, 25, 30);
  print(head);
}
