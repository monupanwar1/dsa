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

int lengthOfLoop(Node *head)
{
  int times = 1;
  map<Node *, int> mpp;

  Node *temp = head;

  while (temp != nullptr)
  {
    if (mpp.find(temp) != mpp.end())
    {
      int value = mpp[temp];
      return times - value;
    }

    mpp[temp] = times;
    times++;
    temp = temp->next;
  }

  return 0;
}

int lengthOfLoop2(Node *head)
{
  Node *slow = head;
  Node *fast = head;

  while (fast != nullptr && fast->next != nullptr)
  {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
    {
      int count = 1;

      Node *temp = slow->next;

      while (temp != slow)
      {
        count++;
        temp = temp->next;
      }
      return count;
    }
  }
  return 0;
}

int main()
{
  vector<int> arr = {1, 2, 3, 4, 5, 8};

  Node *head = arrToLL(arr);

  Node *temp = head;

  // Loop starts at node 3
  Node *loopNode = head->next->next;

  // Go to last node
  while (temp->next != nullptr)
  {
    temp = temp->next;
  }

  // 8 -> 3
  temp->next = loopNode;

  cout << lengthOfLoop(head) << endl;
  cout << lengthOfLoop2(head) << endl;
}
