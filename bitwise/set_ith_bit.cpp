#include <bits/stdc++.h>
using namespace std;

int setIthBit(int n, int i)
{
  return n | (1 << i);
}

int main()
{
  int n = 2;
  int i = 2;
  cout << setIthBit(n, i) << endl;
}