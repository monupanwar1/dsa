#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
  int l = 0;
  int r = s.size() - 1;

  while (l < r)
  {
    if (s[l] != s[r])
    {
      return false;
    }
    l++;
    r--;
  }
  return true;
}

void solve(int idx, string s, vector<string> &path, vector<vector<string>> &ans)
{

  if (idx == s.size())
  {
    ans.push_back(path);
    return;
  }

  for (int i = idx; i < s.size(); i++)
  {
    string substring = s.substr(idx, i - idx + 1);

    if (isPalindrome(substring))
    {
      path.push_back(substring);

      solve(i + 1, s, path, ans);

      path.pop_back();
    }
  }
}

int main()
{
  string s = "aab";
  vector<vector<string>> ans;
  vector<string> path;

  solve(0, s, path, ans);

  for (auto it : ans)
  {
    for (auto x : it)
    {
      cout << x << " ";
    }
    cout << endl;
  }
}