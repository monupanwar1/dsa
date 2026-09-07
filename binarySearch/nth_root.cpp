#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int NthRoot(int n, int m)
{

  for (int i = 1; i <= m; i++)
  {
    int value = pow(i, n);

    if (value == m)
    {
      return i;
    }

    if (value > m)
    {
      break;
    }
  }

  return -1;
}

int NthRoot2(int n, int m)
{

  int low = 1;
  int high = m;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    int value = pow(mid, n);

    if (value == m)
    {
      return mid;
    }

    if (value < mid)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }

  return -1;
}
int main()
{
  int n = 4;
  int m = 64;

  cout << NthRoot(n, m) << endl;
  cout << NthRoot2(n, m) << endl;

  return 0;
}