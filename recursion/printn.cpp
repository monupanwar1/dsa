#include <iostream>
using namespace std;

void printN(int x, int n)
{
  if (n == 0)
    return;
  cout << x << endl;

  printN(x, n - 1);
}
int main()
{
  int x = 3;
  int n = 4;
  printN(x, n);
  return 0;
}