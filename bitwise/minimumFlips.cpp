#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a = 5;
  int b = 7;

  int x = a ^ b;
  int count = 0;

  for (int i = 0; i < 32; i++)
  {
    if (x & (1 << i))
    {
      count++;
    }
  }

  cout << "Minimum flips: " << count << endl;

  return 0;
}