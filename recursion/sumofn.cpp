#include <iostream>
using namespace std;

int sum = 0;

void printN(int i, int n)
{
  if (i > n)
    return;
  sum += i;
  printN(i + 1, n);
}

int printN2(int i, int n)
{
  if (i > n)
    return 0;

  return i + printN2(i + 1, n);
}

int main()
{
  int i = 1;
  int n = 10;
  printN(i, n);
  cout << sum;
  cout << "_____________________Break___________"<<endl;
  cout << printN2(i, n);
}