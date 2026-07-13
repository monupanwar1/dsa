#include <iostream>
using namespace std;
int largestNo(int n)
{
  int largest = 0;
  while (n > 0)
  {
    int lastDigit = n % 10;
    if (lastDigit > largest)
    {
      largest = lastDigit;
    }
    n /= 10;
  }
  return largest;
}
int main()
{
  int n = 778;
  cout << largestNo(n);
  return 0;
}