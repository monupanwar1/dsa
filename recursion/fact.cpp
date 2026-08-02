#include <iostream>
using namespace std;

int ans = 1;

void fact(int i, int n)
{
  if (i > n)
  {
    return;
  }

  ans *= i;

  fact(i + 1, n);
}

int fact2(int i, int n)
{
  if (i > n)
  {
    return 1;
  }

  return i * fact2(i + 1, n);
}

int main()
{

  int n = 4;
  fact(1, n);
  cout << ans << endl;
  cout << fact2(1, n);
}