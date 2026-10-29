#include <iostream>
using namespace std;

struct Stack
{
  int arr[5];
  int top = -1;
};
void push(Stack &s, int x)
{

  if (s.top == 4)
  {
    cout << "Stack Full\n";
    return;
  }
  s.top++;
  s.arr[s.top] = x;
}

void pop(Stack &s)
{

  if (s.top == -1)
  {
    cout << "Stack Empty\n";
    return;
  }
  s.top--;
}

int getTop(Stack &s)
{
  if (s.top == -1)
  {
    return -1;
  }

  return s.arr[s.top];
}
int size(Stack &s)
{
  return s.top + 1;
}

bool isEmpty(Stack &s)
{
  return s.top == -1;
};

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