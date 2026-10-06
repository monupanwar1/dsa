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

  for (int i = 1; i < arr.size(); i++)
  {
    temp->next = new Node(arr[i]);
    temp = temp->next;
  }

  return head;
}

Node *findKthNode(Node *head, int k)
{
  int count = 1;

  Node *temp = head;

  while (temp != nullptr && count < k)
  {
    temp = temp->next;
    count++;
  }

  return temp;
}

Node *reverseLL(Node *head)
{
  Node *prev = nullptr;
  Node *temp = head;

  while (temp != nullptr)
  {
    Node *next = temp->next;

    temp->next = prev;
    prev = temp;
    temp = next;
  }

  return prev;
}

Node *reverseKGroup(Node *head, int k)
{
  Node *temp = head;
  Node *prevLast = nullptr;
  Node *newHead = nullptr;

  while (temp != nullptr)
  {
    // Find kth node
    Node *kth = findKthNode(temp, k);

    // Less than k nodes remaining
    if (kth == nullptr)
    {
      if (prevLast != nullptr)
      {
        prevLast->next = temp;
      }

      break;
    }

    // Save next group
    Node *nextGroup = kth->next;

    // Break current group
    kth->next = nullptr;

    // First node becomes last after reversal
    Node *groupLast = temp;

    // Reverse current group
    Node *reversedHead = reverseLL(temp);

    // First reversed group becomes new head
    if (newHead == nullptr)
    {
      newHead = reversedHead;
    }

    // Connect previous group
    if (prevLast != nullptr)
    {
      prevLast->next = reversedHead;
    }

    // Update previous group's last node
    prevLast = groupLast;

    // Move to next group
    temp = nextGroup;
  }

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
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};

  Node *head = arrToLL(arr);

  int k = 3;

  head = reverseKGroup(head, k);

  printLL(head);

  return 0;
}