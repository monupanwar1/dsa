#include <iostream>
using namespace std;

void reverseStr(int l, int r, string &s)
{
  if (l >= r)
    return;

  swap(s[l], s[r]);
  reverseStr(l + 1, r - 1, s);
}

int main()
{
  string s = "Ballu";
  int l = 0;
  int r = s.length() - 1;
  reverseStr(l, r, s);
  cout << s << endl;
}