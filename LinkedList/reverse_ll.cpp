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

Node *reverseLL(Node *head)
{
  if (head == nullptr || head->next == nullptr)
  {
    return head;
  };

  Node *temp = head;
  stack<int> st;

  while (temp != nullptr)
  {
    st.push(temp->data);
    temp = temp->next;
  }
  temp = head;

  while (temp != nullptr)
  {
    temp->data = st.top();
    st.pop();
    temp = temp->next;
  }
  return head;
}

Node *reverseLL2(Node *head)
{
  if (head == nullptr || head->next == nullptr)
  {
    return head;
  };

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
}

int main()
{
  vector<int> arr = {1, 2, 3, 4, 5};

  Node *head1 = arrayToLinkedList(arr);
  Node *head2 = arrayToLinkedList(arr);

  cout << "Original Linked List: ";
  printLL(head1);

  head1 = reverseLL(head1);

  cout << "Reversed Linked List: ";
  printLL(head1);

  cout << "Original Linked List----2: ";
  printLL(head2);

  head2 = reverseLL2(head2);

  cout << "Reversed Linked List: ";
  printLL(head2);

  return 0;
}