#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n)
{

  if (n <= 0)
  {
    return false;
  }

  while (n > 1)
  {
    if (n % 2 != 0)
    {
      return false;
    }
    n /= 2;
  };

  return true;
}

bool isPowerOfTwo1(int n)
{
  return n > 0 && (n & (n - 1)) == 0;
}

int main()
{
  int n = 16;

  if (isPowerOfTwo1(n))
    cout << "Power of 2";
  else
    cout << "Not Power of 2";

  return 0;
}