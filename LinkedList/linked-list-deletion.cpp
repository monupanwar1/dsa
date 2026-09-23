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

  Node(int data, Node *next)
  {
    this->data = data;
    this->next = next;
  }
};

Node *arrayToLinkedList(vector<int> &arr)
{
  int n = arr.size();

  Node *head = new Node(arr[0]); // head node
  Node *temp = head;

  for (int i = 1; i < n; i++)
  {
    temp->next = new Node(arr[i]);
    temp = temp->next;
  }
  return head;
}

Node *print(Node *head)
{
  Node *temp = head;

  while (temp != nullptr)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

Node *removeHead(Node *head)
{

  if (head == nullptr || head->next == nullptr)
  {
    return head;
  }

  Node *temp = head;
  head = head->next;

  delete (temp);

  return head;
}

Node *removeTail(Node *head)
{

  Node *temp = head;

  while (temp->next->next != nullptr)
  {
    temp = temp->next;
  }

  // store last
  Node *last = temp->next;

  // link to nullptr
  temp->next = nullptr;

  // free
  delete (temp->next);

  return head;
}

Node *removeK(Node *head, int k)
{

  // edge case
  if (head == nullptr || head->next == nullptr)
  {
    return head;
  }

  // first elem
  if (k == 1)
  {
    Node *temp = head;
    head = head->next;
    delete (temp);

    return head;
  }

  Node *temp = head;
  int count = 1;

  while (temp != nullptr)
  {
    if (count == k - 1)
    {
      break;
    }
    temp = temp->next;
    count += 1;
  }

  Node *nodeToDelete = temp->next;
  temp->next = temp->next->next;

  delete nodeToDelete;

  return head;
}

int main()
{
  vector<int> arr = {1, 2, 3, 4};

  Node *head = arrayToLinkedList(arr);

  head = removeK(head, 4);

  print(head);
}