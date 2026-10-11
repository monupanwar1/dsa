#include <bits/stdc++.h>
using namespace std;

int xor1ToNOpt(int n)
{
  if (n % 4 == 0)
    return n;
  if (n % 4 == 1)
    return 1;
  if (n % 4 == 2)
    return n + 1;

  return 0;
}

int xor1ToN(int n)
{
  int xor1 = 0;

  for (int i = 1; i <= n; i++)
  {
    xor1 = xor1 ^ i;
  }

  return xor1;
}

int xorRange(int L, int R)
{
  return xor1ToNOpt(L - 1) ^ xor1ToNOpt(R);
}

int main()
{
  int n = 12;

  cout << xor1ToN(n) << endl;
  cout << xor1ToNOpt(n) << endl;
  cout << xorRange(1, 5) << endl;

  return 0;
}