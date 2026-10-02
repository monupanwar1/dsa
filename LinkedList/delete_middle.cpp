#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int data)
  {
    this->data = data;
    this->next = nullptr;
  }
};

Node *arrayToLinkedList(vector<int> &arr)
{
  if (arr.empty())
    return nullptr;

  Node *head = new Node(arr[0]);
  Node *temp = head;

  for (int i = 1; i < arr.size(); i++)
  {
    temp->next = new Node(arr[i]);
    temp = temp->next;
  }

  return head;
}

void printList(Node *head)
{
  while (head != nullptr)
  {
    cout << head->data << " ";
    head = head->next;
  }

  cout << endl;
}

Node *deleteMiddle(Node *head)
{

  if (head == nullptr || head->next == nullptr)
  {
    return nullptr;
  }

  Node *temp = head;
  int len = 0;

  while (temp != nullptr)
  {
    len += 1;
    temp = temp->next;
  }

  int count = len / 2 - 1;

  Node *prev = head;

  while (count--)
  {
    prev = prev->next;
  }

  temp = prev->next;
  prev->next = temp->next;
  delete temp;

  return head;
};

Node *deleteMiddle2(Node *head)
{

  if (head == nullptr || head->next == nullptr)
  {
    return nullptr;
  }

  Node *slow = head;
  Node *fast = head;
  Node *prev = nullptr;

  while (fast != nullptr && fast->next != nullptr)
  {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }

  prev->next = slow->next;

  return head;
};

int main()
{
  vector<int> arr = {10, 20, 30, 40, 50};

  Node *head = arrayToLinkedList(arr);

  cout << "Before: ";
  printList(head);

  head = deleteMiddle(head);

  cout << "After: ";
  printList(head);

  head = deleteMiddle2(head);

  cout << "After: ";
  printList(head);

  return 0;
}