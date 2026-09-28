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
  int n = arr.size();

  if (arr.empty())
  {
    return nullptr;
  }

  Node *head = new Node(arr[0]);
  Node *temp = head;

  for (int i = 1; i < n; i++)
  {
    temp->next = new Node(arr[i]);
    temp = temp->next;
  }
  return head;
}

void print(Node *head)
{

  Node *temp = head;
  while (temp != nullptr)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

Node *sumOfLL(Node *head1, Node *head2)
{
  vector<int> arr;
  int carr = 0;

  while (head1 != nullptr || head2 != nullptr)
  {
    int sum = carr;

    if (head1 != nullptr)
    {
      sum += head1->data;
      head1 = head1->next;
    }

    if (head2 != nullptr)
    {
      sum += head2->data;
      head2 = head2->next;
    }

    arr.push_back(sum % 10);

    carr = sum / 10;
  }
  
  if (carr != 0)
  {
    arr.push_back(carr);
  }

  Node *dummy = new Node(0);
  Node *temp = dummy;

  for (auto it : arr)
  {
    temp->next = new Node(it);
    temp = temp->next;
  }
  return dummy->next;
};

int main()
{
  vector<int> arr1 = {2, 4, 3};
  vector<int> arr2 = {5, 6, 4};

  Node *head1 = arrToLL(arr1);
  Node *head2 = arrToLL(arr2);

  cout << "LL1: ";
  print(head1);

  cout << "LL2: ";
  print(head2);

  Node *result = sumOfLL(head1, head2);

  cout << "Sum: ";
  print(result);

  return 0;
}