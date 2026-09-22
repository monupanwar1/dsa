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

  // create head
  Node *head = new Node(arr[0]);

  // temp
  Node *temp = head;

  for (int i = 1; i < n; i++)
  {
    // make temp node and connect to prev
    temp->next = new Node(arr[i]);
    // move to next
    temp = temp->next;
  }

  return head;
};

int main()
{
  vector<int> arr = {10, 20, 30, 40};

  Node *head = arrayToLinkedList(arr);

  // print the linked list
  Node *temp = head;

  while (temp != nullptr)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
}