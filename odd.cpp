#include <iostream>

using namespace std;

bool isOdd(int n)
{
  if (n % 2 == 1)
  {
    return true;
  }
  else
  {
    return false;
  }
}
int main()
{

  int n = 2;
  if (isOdd(n))
  {
    cout << "odd";
  }
  else
  {
    cout << "not odd";
  }
}