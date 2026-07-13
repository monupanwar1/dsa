#include <iostream>
#include <cmath>
using namespace std;
// brute
int perfect(int n)
{
  int sum = 0;

  for (int i = 1; i < n; i++)
  {
    if (n % i == 0)
    {
      sum += i;
    }
  }

  return (sum == n);
}

int perfect1(int n)
{
  int sum = 1;

  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      sum += i;

      if (i != (n / i))
      {
        sum += (n / i);
      }
    }
  }

  return (sum == n);
}

int main()
{
  int n = 28;
  cout << perfect1(n);
}