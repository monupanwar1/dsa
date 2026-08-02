#include <iostream>
using namespace std;
bool isPalidrome(int l, int r, string &s)
{

  if (l >= r)
  {
    return true;
  }

  if (s[l] != s[r])
  {
    return false;
  }

  isPalidrome(l + 1, r - 1, s);
}

int main()
{
  string s = "MADEAM";
  int l = 0;
  int r = s.length() - 1;
  cout << isPalidrome(l, r, s);
  return 0;
}