#include <iostream>
using namespace std;

int fibo(int n)
{
  if (n <= 1)
    return n;

  int last = 1;
  int slast = 0;
  int curr = 0;

  for (int i = 2; i <= n; i++)
  {
    curr = last + slast;
    slast = last;
    last = curr;
  }
  return curr;
}

int fibon(int n)
{
  if (n <= 1)
    return n;

  return fibon(n - 1) + fibo(n - 2);
}

int main()
{
  int n = 6;
  cout << fibo(n);
  cout << endl;
  cout << fibon(n);
}