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

Node *arrayToLinkedList(vector<int> arr)
{

  if (arr.empty())
  {
    return nullptr;
  }

  Node *head = new Node(arr[0]);
  Node *temp = head;

  for (int i = 1; i < arr.size(); i++)
  {
    temp->next = new Node(arr[i]);
    temp = temp->next;
  }
  return head;
};

void printLL(Node *head)
{
  Node *temp = head;

  while (temp != nullptr)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

Node *reverseLL(Node *&head)
{
  Node *temp = head;
  Node *front = temp;
  Node *prev = nullptr;

  while (temp != nullptr)
  {
    front = temp->next;
    temp->next = prev;
    prev = temp;
    temp = front;
  }
  return prev;
};

Node *addOne(Node *&head)
{
  int carry = 1;

  // rev

  Node *revHead = reverseLL(head);
  Node *temp = revHead;

  // add one

  while (temp != nullptr)
  {
    int sum = temp->data + carry;

    // if sum is under 10 simply return;
    if (sum < 10)
    {
      temp->data = sum;
      carry = 0;
      break;
    }
    
    temp->data = 0;
    carry = 1;

    temp = temp->next;
  }

  if (carry != 0)
  {
    Node *newNode = new Node(carry);
    newNode->next = revHead;
    revHead = revHead;
    return newNode;
  }

  return reverseLL(revHead);
};

int main()
{

  vector<int> arr = {9, 9};

  Node *head = arrayToLinkedList(arr);

  cout << "Original: ";
  printLL(head);

  head = addOne(head);

  cout << "After adding 1: ";
  printLL(head);

  return 0;
}