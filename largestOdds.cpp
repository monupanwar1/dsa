#include <iostream>
using namespace std;

string largestOddNumber(string num)
{
  int n = num.length();
  int ans = -1;

  for (int i = n - 1; i >= 0; i--)
  {
    // check odd
    if ((num[i] - '0') % 2 != 0)
    {
      ans = i;
      break;
    }
  }

  //  not contain any odd
  if (ans == -1)
  {
    return "";
  }
  int left = 0;
  // check non zero
  for (int i = 0; i <= ans; i++)
  {
    if (num[i] != '0')
    {
      left = i;
      break;
    }
  }
  return num.substr(left, ans - left + 1);
}

int main()
{
  string num = "0102457";
  cout << "Largest Odd Number: " << largestOddNumber(num) << endl;
}