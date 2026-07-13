#include <iostream>
#include <cmath>
using namespace std;

int arms(int n)
{
  int sum = 0;
  int dup = n;
  int cnt = log10(n) + 1;

  while (n > 0)
  {
    int lastdigit = n % 10;
    sum += round(pow(lastdigit, cnt));

    n /= 10;
  }

  return (dup == sum);
}

int main()
{
  int n = 153;
  cout << arms(n);
}