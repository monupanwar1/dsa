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

void printList(Node *head)
{
  while (head != nullptr)
  {
    cout << head->data << " ";
    head = head->next;
  }

  cout << endl;
}

bool detectLoop(Node *head)
{

  map<Node *, bool> mpp;
  Node *temp = head;

  while (temp != nullptr)
  {
    if (mpp.find(temp) != mpp.end())
    {
      return true;
    }
    mpp[temp] = 1;
    temp = temp->next;
  }
  return false;
};

bool detectLoop(Node *head)
{

  Node *slow = head;
  Node *fast = head;

  while (fast != nullptr && fast->next != nullptr)
  {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
    {
      return true;
    }
  }
  return false;
}

int main()
{
  vector<int> arr = {1, 2, 3, 4, 5};

  Node *head = arrToLL(arr);

  Node *temp = head;

  Node *loopNode = temp->next->next;

  while (temp->next != nullptr)
  {
    temp = temp->next;
  }
  temp->next = loopNode;

  cout << detectLoop(head) << endl;
}