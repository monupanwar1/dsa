#include <bits/stdc++.h>
using namespace std;

struct Queue
{
  stack<int> s1, s2;
};

void push(Queue &q, int x)
{
  q.s1.push(x);
}

void pop(Queue &q)
{
  if (q.s1.empty() && q.s2.empty())
  {
    cout << "Queue Empty\n";
    return;
  }

  if (q.s2.empty())
  {
    while (!q.s1.empty())
    {
      q.s2.push(q.s1.top());
      q.s1.pop();
    }
  }
  q.s2.pop();
}

int getFront(Queue &q)
{
  if (q.s1.empty() && q.s2.empty())
  {
    return -1;
  }

  if (q.s2.empty())
  {
    while (!q.s1.empty())
    {
      q.s2.push(q.s1.top());
      q.s1.pop();
    }
  }

  return q.s2.top();
}
bool isEmpty(Queue &q)
{
  return q.s1.empty() && q.s2.empty();
}

int main()
{
  Queue q;

  push(q, 10);
  push(q, 20);
  push(q, 30);

  cout << getFront(q) << endl; // 10

  pop(q);

  cout << getFront(q) << endl; // 20

  return 0;
}