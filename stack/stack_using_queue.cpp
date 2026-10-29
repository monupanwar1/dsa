#include <iostream>
#include <queue>
using namespace std;

struct Stack
{
  queue<int> q;
};

void push(Stack &st, int x)
{
  int n = st.q.size();

  st.q.push(x);
  
  // move elem 
  while (n--)
  {
    st.q.push(st.q.front());
    st.q.pop();
  }
}

void pop(Stack &st)
{
  if (st.q.empty())
  {
    cout << "Stack Empty\n";
    return;
  }

  st.q.pop();
}

int getTop(Stack &st)
{
  if (st.q.empty())
    return -1;

  return st.q.front();
}

int size(Stack &st)
{
  return st.q.size();
}

bool isEmpty(Stack &st)
{
  return st.q.empty();
}

int main()
{
  Stack st;

  push(st, 10);
  push(st, 20);
  push(st, 30);

  cout << getTop(st) << endl; // 30

  pop(st);

  cout << getTop(st) << endl; // 20
  cout << size(st) << endl;   // 2

  return 0;
}