#include <iostream>
using namespace std;

int count(int num)
{
  if (num == 0)
    return 1;

  int odd = 0;
  while (num > 0)
  {
    int digit = num % 10;
    if (digit % 2 == 1)
    {
      odd += 1;
    }
    num /= 10;
  }
  return odd;
}
int main()
{
  int digit = 2445;
  cout << count(digit);
  return 0;
}