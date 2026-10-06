#include <bits/stdc++.h>
using namespace std;

int binaryToDecimal(string x)
{

  int p2 = 1;
  int num = 0;
  int n = x.size();

  for (int i = n - 1; i >= 0; i--)
  {
    if (x[i] == '1')
    {
      num += p2;
    }
    p2 *= 2;
  }
  return num;
};

int main()
{
  string binary;
  cin >> binary;

  cout << binaryToDecimal(binary) << endl;
  return 0;
}