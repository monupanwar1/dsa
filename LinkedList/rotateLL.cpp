#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *next;

  Node(int data)
  {
    this->data = data;
    next = nullptr;
  }
};

Node *arrToLL(vector<int> &arr)
{
  if (arr.empty())
    return nullptr;

  Node *head = new Node(arr[0]);
  Node *temp = head;

  int i = 1;

  while (i < arr.size())
  {
    temp->next = new Node(arr[i]);
    temp = temp->next;
    i++;
  }

  return head;
}

// Find length + last node
pair<int, Node *> findLastAndLength(Node *head)
{
  int length = 0;
  Node *temp = head;
  Node *last = nullptr;

  while (temp != nullptr)
  {
    last = temp;
    temp = temp->next;
    length++;
  }

  return {length, last};
}

// Find kth node
Node *findKthNode(Node *head, int k)
{
  Node *temp = head;
  int count = 1;

  while (temp != nullptr && count < k)
  {
    temp = temp->next;
    count++;
  }

  return temp;
}

Node *rotateLL(Node *head, int k)
{
  if (head == nullptr || head->next == nullptr || k == 0)
    return head;

  pair<int, Node *> result = findLastAndLength(head);

  int length = result.first;
  Node *lastNode = result.second;

  k = k % length;

  if (k == 0)
    return head;

  int position = length - k;

  Node *kthNode = findKthNode(head, position);

  Node *newHead = kthNode->next;

  // Last node connects to old head
  lastNode->next = head;

  // Break at kth node
  kthNode->next = nullptr;

  return newHead;
}

void printLL(Node *head)
{
  while (head != nullptr)
  {
    cout << head->data << " ";
    head = head->next;
  }

  cout << endl;
}

int main()
{
  vector<int> arr = {1, 2, 3, 4, 5};

  Node *head = arrToLL(arr);

  int k = 2;

  head = rotateLL(head, k);

  printLL(head);

  return 0;
}