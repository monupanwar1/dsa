#include <iostream>
#include <vector>
#include <string>
using namespace std;

string phone[] = {
    "", "", "abc", "def", "ghi",
    "jkl", "mno", "pqrs", "tuv", "wxyz"};

void solve(int idx, string digits, string &temp,
           vector<string> &ans)
{
  // your code
  if (idx == digits.size())
  {
    ans.push_back(temp);
    return;
  }

  int nums = digits[idx] - '0';
  string letter = phone[nums];

  for (int i = 0; i < letter.size(); i++)
  {
    temp.push_back(letter[i]);
    solve(idx + 1, digits, temp, ans);
    temp.pop_back();
  }
}

int main()  
{
  string digits = "23";

  string temp;
  vector<string> ans;

  solve(0, digits, temp, ans);

  for (auto &s : ans)
  {
    cout << s << endl;
  }

  return 0;
}