#include <bits/stdc++.h>
using namespace std;
int xor1ToN(int n)
{

  int xor1 = 0;

  for (int i = 1; i <= n; i++)
  {
    xor1 = xor1 ^ i;
  }
  return xor1;
}

int main()
{
  int n = 10;

  cout << xor1ToN(n) << endl;

  return 0;
}