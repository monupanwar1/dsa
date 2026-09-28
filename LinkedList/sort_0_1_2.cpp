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

Node *sort012(Node *head)
{
  if (head == nullptr || head->next == nullptr)
    return head;

  int count0 = 0, count1 = 0, count2 = 0;

  Node *temp = head;

  while (temp != nullptr)
  {
    if (temp->data == 0)
    {
      count0++;
    }
    else if (temp->data == 1)
    {
      count1++;
    }
    else
    {
      count2++;
    }
    temp = temp->next;
  }

  temp = head;

  while (temp != nullptr)
  {
    if (count0 > 0)
    {
      temp->data = 0;
      count0--;
    }
    else if (count1 > 0)
    {
      temp->data = 1;
      count1--;
    }
    else
    {
      temp->data = 2;
      count2--;
    }
    temp = temp->next;
  }

  return head;
}

int main()
{
  vector<int> arr = {2, 1, 0, 2, 1, 0};

  Node *head = arrToLL(arr);

  cout << "Original: ";
  print(head);

  head = sort012(head);

  cout << "Sorted: ";
  print(head);

  return 0;
}