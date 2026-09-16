#include <iostream>
using namespace std;

int powerOfX(int x, int n)
{
  int ans = 1;

  for (int i = 0; i < n; i++)
  {
    ans *= x;
  }
  return ans;
}

int powerOfX2(int x, int n)
{

  if (n == 0)
    return 1;

  return x * powerOfX2(x, n - 1);
}

int main()
{
  int x = 2;
  int n = 10;

  cout << powerOfX(x, n) << endl;

  return 0;
}