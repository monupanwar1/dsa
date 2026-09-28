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

Node *segregateOddEven(Node *head)
{
  if (head == nullptr || head->next == nullptr)
  {
    return head;
  }

  vector<int> arr;

  Node *temp = head;

  while (temp != nullptr)
  {
    arr.push_back(temp->data);

    if (temp->next == nullptr)
    {
      break;
    }
    temp = temp->next->next;
  }

  temp = head->next;

  while (temp != nullptr)
  {
    arr.push_back(temp->data);

    if (temp->next == nullptr)
    {
      break;
    }
    temp = temp->next->next;
  }

  temp = head;

  for (int i = 0; i < arr.size(); i++)
  {
    temp->data = arr[i];
    temp = temp->next;
  }
  return head;
}

Node *segregateOddEven2(Node *head)
{
  if (head == nullptr || head->next == nullptr)
  {
    return head;
  }

  Node *odd = head;
  Node *even = head->next;

  while (even != nullptr && even->next != nullptr)
  {
    odd->next = odd->next->next;
    odd = odd->next;

    even->next = even->next->next;
    even = even->next;
  }

  odd->next = head->next;

  return head;
}

int main()
{
  vector<int> arr = {1, 2, 3, 4, 5, 6};

  Node *head1 = arrToLL(arr);
  Node *head2 = arrToLL(arr);

  cout << "Original: ";
  print(head1);
  head1 = segregateOddEven(head1);

  cout << "Result: ";
  print(head1);

  cout << "Original: ";
  print(head2);
  head2 = segregateOddEven(head2);
  cout << "Result: ";
  print(head2);

  return 0;
}