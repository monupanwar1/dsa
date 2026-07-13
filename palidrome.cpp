#include <iostream>
using namespace std;

bool palidrome(int n)
{
  int orignal = n;
  int rn = 0;
  while (n > 0)
  {
    int lastdigit = n % 10;

    rn = rn * 10 + lastdigit;

    n /= 10;
  }

  return rn == orignal;
}
int main()
{
  int n = 222;

  if (palidrome(n))
  {
    cout << "Palindrome";
  }
  else
  {
    cout << "Not a Palindrome";
  }

 
}