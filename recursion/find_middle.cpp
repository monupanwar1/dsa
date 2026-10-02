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
};

void printList(Node *head)
{
  while (head != nullptr)
  {
    cout << head->data << " ";
    head = head->next;
  }

  cout << endl;
}

Node *findMiddle(Node *head)
{
  if (head == nullptr || head->next == nullptr)
  {
    return head;
  }

  Node *temp = head;
  int len = 0;

  while (temp != nullptr)

  {
    len += 1;
    temp = temp->next;
  }

  int count = len / 2;
  temp = head;

  while (count--)

  {
    temp = temp->next;
  }
  return temp;
}

Node *findMiddle2(Node *head)
{
  if (head == nullptr || head->next == nullptr)
  {
    return head;
  }

  Node *slow = head;
  Node *fast = head;

  while (fast != nullptr && fast->next != nullptr)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

int main()
{
  vector<int> arr = {10, 20, 30, 40, 50, 60};

  Node *head = arrayToLinkedList(arr);

  cout << "Linked List: ";
  printList(head);

  Node *middle = findMiddle(head);

  cout << "Middle: " << middle->data << endl;

  cout << "Linked List 2: ";
  printList(head);

  Node *middle2 = findMiddle2(head);

  cout << "Middle: " << middle2->data << endl;

  return 0;
}