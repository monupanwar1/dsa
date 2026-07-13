#include <iostream>
using namespace std;

int reverse(int n)
{
  int rn = 0;
  while (n > 0)
  {
    int lastdigit = n % 10;

    rn = rn * 10 + lastdigit;
    n /= 10;
  }

  return rn;
}
int main()
{
  int n = 1234;

  cout << reverse(n);
  return 0;
}