#include <bits/stdc++.h>
using namespace std;

void reverseString(string &ans)
{
  int left = 0;
  int right = ans.size() - 1;

  while (left < right)
  {
    swap(ans[left], ans[right]);
    left++;
    right--;
  }
}

string decimalToBinary(int n)
{
  if (n == 0)
    return "0";

  string ans = "";

  while (n != 1)
  {
    int rem = n % 2;

    if (rem == 1)
    {
      ans += '1';
    }
    else
    {
      ans += '0';
    }

    n = n / 2;
  }

  ans += '1';

  reverseString(ans);

  return ans;
}

int main()
{
  int n;
  cin >> n;

  cout << decimalToBinary(n) << endl;

  return 0;
}