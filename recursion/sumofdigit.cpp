#include <iostream>
using namespace std;

int sum(int n)
{
  if (n == 0)
    return 0;

  int lastDigit = n % 10;

  return lastDigit + sum(n / 10);
}

int sumofDigi(int n)
{
  if (n < 10)
  {
    return n;
  }
  return sumofDigi(sum(n));
}

int main()
{
  int n = 4;
  cout << sumofDigi(n);
}