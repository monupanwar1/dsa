#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

struct Queue
{
  Node *front = nullptr;
  Node *rear = nullptr;
};

void push(Queue &q, int x)
{
  Node *newNode = new Node;
  newNode->data = x;
  newNode->next = nullptr;

  if (q.front == nullptr)
  {
    q.front = newNode;
    q.rear = newNode;
  }
  else
  {
    q.rear->next = newNode;
    q.rear = newNode;
  }
}

void pop(Queue &q)
{
  if (q.front == nullptr)
  {
    cout << "Queue Empty\n";
    return;
  }
  Node *temp = q.front;
  q.front = q.front->next;

  if (q.front == nullptr)
  {
    q.rear = nullptr;
  }

  delete temp;
}

int getFront(Queue &q)
{
  if (q.front == nullptr)
    return -1;
  return q.front->data;
}

int isEmpty(Queue &q)
{

  return q.front == nullptr;
}

int size(Queue &q)
{
  int count = 0;
  Node *temp = q.front;
  while (temp != nullptr)
  {
    count++;
    temp = temp->next;
  }
  return count;
}

int main()
{
  Queue q;

  push(q, 10);
  push(q, 20);
  push(q, 30);

  cout << getFront(q) << endl; // 10
  cout << size(q) << endl;     // 3

  pop(q);

  cout << getFront(q) << endl; // 20
  cout << size(q) << endl;     // 2

  cout << isEmpty(q) << endl; // 0

  return 0;
}