#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *prev;
  Node *next;

public:
  Node(int data)
  {
    this->data = data;
    this->prev = nullptr;
    this->next = nullptr;
  }

public:
  Node(int data, Node *prev, Node *next)
  {
    this->data = data;
    this->prev = prev;
    this->next = next;
  }
};

Node *arrayToLinkedList(vector<int> &arr)
{
  int n = arr.size();

  Node *head = new Node(arr[0]);
  Node *temp = head;

  for (int i = 1; i < n; i++)
  {
    temp->next = new Node(arr[i]);
    temp->next->prev = temp;
    temp = temp->next;
  }

  return head;
}

void print(Node *head)
{
  Node *temp = head;

  while (temp != nullptr)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
};

Node *deleteHead(Node *head)
{
  if (head == nullptr)
  {
    return nullptr;
  }
  if (head->next == nullptr)
  {
    delete (head);
    return nullptr;
  }

  Node *temp = head;
  head = head->next;
  head->prev = nullptr;
  delete temp;

  return head;
}

Node *deleteTail(Node *head)
{
  if (head == nullptr)
  {
    return nullptr;
  }

  if (head->next == nullptr)
  {
    delete head;
    return nullptr;
  }

  Node *temp = head;

  while (temp->next != nullptr)
  {
    temp = temp->next;
  }
  Node *prev = temp->prev;
  prev->next = nullptr;

  delete temp;

  return head;
}

Node *deleteKth(Node *head, int k)
{
  if (head == nullptr || k <= 0)
  {
    return head;
  }

  if (head->next == nullptr && k == 1)
  {
    delete head;
    return nullptr;
  }

  if (k == 1)
  {
    Node *temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
    return head;
  }

  int count = 1;

  Node *temp = head;

  while (temp->next != nullptr)
  {
    if (count == k)
    {
      Node *prev = temp->prev;

      prev->next = temp->next;
      temp->next->prev = prev;

      delete temp;
      return head;
    }

    temp = temp->next;
    count++;
  }

  if (count == k)
  {
    Node *prev = temp->prev;
    prev->next = nullptr;

    delete temp;
  }

  return head;
}

int main()
{
  vector<int> arr = {1, 2, 3, 4, 5};

  Node *head = arrayToLinkedList(arr);

  // head = deleteHead(head);
  // head = deleteTail(head);
  head = deleteKth(head, 1);

  print(head);

  return 0;
}