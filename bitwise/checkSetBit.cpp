#include <bits/stdc++.h>
using namespace std;

bool checkBit(int i, int n)
{
  return (n & (1 << i)) != 0;
}

int main()
{
  int n = 13;
  int i = 2;

  if (checkBit(i, n))
  {
    cout << "set bit" << endl;
  }
  else
  {
    cout << "not set bit" << endl;
  }
}