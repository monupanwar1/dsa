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

Node *findLoopStart(Node *head)
{
  map<Node *, bool> mpp;

  Node *temp = head;

  while (temp != nullptr)

  {
    if (mpp.find(temp) != mpp.end())
    {
      return temp;
    }
    mpp[temp] = 1;
    temp = temp->next;
  }
  return nullptr;
}

Node *findLoopStart2(Node *head)
{
  Node *slow = head;
  Node *fast = head;

  while (fast != nullptr && fast->next != nullptr)
  {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
    {
      slow = head;

      while (slow != fast)
      {
        slow = slow->next;
        fast = fast->next;
      }
      return slow;
    }
  }
  return nullptr;
}

int main()
{
  vector<int> arr = {1, 2, 3, 4, 5, 8};

  Node *head = arrToLL(arr);

  // Loop starts at node 3
  Node *loopNode = head->next->next;

  // Go to last node
  Node *temp = head;

  while (temp->next != nullptr)
  {
    temp = temp->next;
  }

  // Create loop: 8 -> 3
  temp->next = loopNode;

  Node *result = findLoopStart(head);

  if (result != nullptr)
    cout << "Loop starts at: " << result->data << endl;
  else
    cout << "No loop" << endl;

  cout << "---2----";

  Node *result2 = findLoopStart2(head);

  if (result2 != nullptr)
    cout << "Loop starts at: " << result2->data << endl;
  else
    cout << "No loop" << endl;

  return 0;
}