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

Node *arrToLL(vector<int> &arr)
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

void print(Node *head)
{
  while (head != nullptr)
  {
    cout << head->data << " ";
    head = head->next;
  }

  cout << endl;
}

Node *deleteKthFromEnd(Node *head, int k)
{
  if (head == nullptr || k <= 0)
  {
    return head;
  }

  int count = 0;
  Node *temp = head;

  while (temp != nullptr)
  {
    count++;
    temp = temp->next;
  }

  if (k > count)
  {
    return head;
  }

  if (k == count)
  {
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
  }

  int pos = count - k;

  Node *prev = nullptr;
  Node *curr = head;

  while (pos--)
  {
    prev = curr;
    curr = curr->next;
  }
  
  prev->next = curr->next;
  delete curr;

  return head;
}

int main()
{
  vector<int> arr = {1, 2, 3, 4, 5};

  Node *head = arrToLL(arr);

  cout << "Original: ";
  print(head);

  int k = 1;

  head = deleteKthFromEnd(head, k);

  cout << "After deletion: ";
  print(head);

  return 0;
}