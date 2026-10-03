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

Node *findIntersection(Node *head1, Node *head2)
{
  map<Node *, bool> mpp;

  Node *temp = head1;

  while (temp != nullptr)
  {
    mpp[temp] = true;
    temp = temp->next;
  }

  Node *temp2 = head2;

  while (temp2 != nullptr)
  {
    if (mpp.find(temp2) != mpp.end())
    {
      return temp2;
    }

    temp2 = temp2->next;
  }

  return nullptr;
}

Node *findIntersection2(Node *head1, Node *head2)
{
  Node *p1 = head1;
  Node *p2 = head2;

  while (p1 != p2)
  {
    if (p1 == nullptr)
    {
      p1 = head2;
    }
    else
    {
      p1 = p1->next;
    }
    if (p2 == nullptr)
    {
      p2 = head1;
    }
    else
    {
      p2 = p2->next;
    }
  }
}

int main()
{
  vector<int> arr1 = {1, 2, 3};
  vector<int> arr2 = {4, 5};

  Node *head1 = arrToLL(arr1);
  Node *head2 = arrToLL(arr2);

  // Create common part
  Node *common1 = new Node(7);
  Node *common2 = new Node(8);

  common1->next = common2;

  // Connect both lists to SAME node
  Node *temp1 = head1;

  while (temp1->next != nullptr)
  {
    temp1 = temp1->next;
  }

  temp1->next = common1;

  Node *temp2 = head2;

  while (temp2->next != nullptr)
  {
    temp2 = temp2->next;
  }

  temp2->next = common1;

  printList(head1);
  printList(head2);

  Node *intersection = findIntersection2(head1, head2);

  if (intersection != nullptr)
    cout << "Intersection Node: " << intersection->data << endl;
  else
    cout << "No Intersection" << endl;

  return 0;
}