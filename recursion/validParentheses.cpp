#include <iostream>
#include <vector>
#include <string>
using namespace std;

void generate(int idx, string &str, int open, int close, int n, vector<string> &ans)
{
  if (open > n)
  {
    return;
  }

  if (open + close == 2 * n && open == close)
  {
    ans.push_back(str);
    return;
  }
  if (open < n)
  {
    str.push_back('(');
    generate(idx + 1, str, open + 1, close, n, ans);
    str.pop_back();
  }
  if (open > close)
  {
    str.push_back(')');
    generate(idx + 1, str, open, close + 1, n, ans);
    str.pop_back();
  }
}

vector<string> validParentheses(int n)
{
  vector<string> ans;
  string str = "";

  generate(0, str, 0, 0, n, ans);

  return ans;
}

int main()
{
  int n = 3;

  vector<string> ans = validParentheses(n);

  for (string s : ans)
  {
    cout << s << endl;
  }

  return 0;
}