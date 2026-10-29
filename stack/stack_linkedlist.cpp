#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

struct Stack
{
  Node *top = nullptr;
};

void push(Stack &st, int x)
{
  Node *newNode = new Node;
  newNode->data = x;
  newNode->next = st.top;

  st.top = newNode;
}

void pop(Stack &st)
{
  if (st.top == nullptr)
  {
    cout << "stack is empty/n";
    return;
  }

  Node *temp = st.top;
  st.top = st.top->next;
  delete temp;
}

int getTop(Stack &st)
{
  if (st.top == nullptr)
    return -1;

  return st.top->data;
}

int size(Stack &st)
{
  int count = 0;
  Node *temp = st.top;

  while (temp != nullptr)
  {
    count++;
    temp = temp->next;
  }
  return count;
}

bool isEmpty(Stack &st)
{
  return st.top == nullptr;
}

int main()
{
  Stack st;

  push(st, 10);
  push(st, 20);
  push(st, 30);

  cout << getTop(st) << endl; // 30
  cout << size(st) << endl;   // 3

  pop(st);

  cout << getTop(st) << endl; // 20
  cout << size(st) << endl;   // 2

  cout << isEmpty(st) << endl; // 0

  return 0;
}