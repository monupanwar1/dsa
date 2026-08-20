#include <iostream>
#include <vector>
using namespace std;

int pascalElem(int row, int col)
{
  int n = row - 1;
  int c = col - 1;
  int res = 1;

  for (int i = 0; i < c; i++)
  {

    res *= (n - i);
    res /= (i + 1);
  }

  return res;
}

int main()
{
  int row = 5;
  int col = 3;
  cout << pascalElem(row, col);
  return 0;
}