#include <iostream>
using namespace std;

struct Queue
{
  int arr[5];
  int front = -1;
  int rear = -1;
};

void push(Queue &q, int x)
{
  if (q.rear == 4)
  {
    cout << "Queue Full\n";
    return;
  }
  if (q.front == -1)
  {
    q.front = 0;
  }
  q.rear++;
  q.arr[q.rear] = x;
}
void pop(Queue &q)
{
  if (q.front == -1 || q.front > q.rear)
  {
    cout << "Queue Empty\n";
    return;
  }
  q.front++;
}

int getFront(Queue &q)
{
  if (q.front == -1 || q.front > q.rear)
  {
    return -1;
  }

  return q.arr[q.front];
}
int size(Queue &q)
{
  if (q.front == -1 || q.front > q.rear)
  {
    return 0;
  }

  return q.rear - q.front + 1;
}

bool isEmpty(Queue &q)
{
  return q.front == -1 || q.front > q.rear;
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