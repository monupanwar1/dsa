#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string longestCommonPrefix(vector<string> &strs)
{

  // edge case
  if (strs.empty())
  {
    return "";
  }
  // sort
  sort(strs.begin(), strs.end());

  // take first and last note string have len and vector have size

  string first = strs[0];
  string last = strs[strs.size() - 1];

  // min

  int len = min(first.length(), last.length());

  string ans = "";

  for (int i = 0; i < len; i++)
  {
    if (first[i] == last[i])
    {
      ans += first[i];
    }
    else
    {
      break;
    }
  }

  return ans;
}

int main()
{
  vector<string> strs = {"flower", "flow", "flight"};

  cout << longestCommonPrefix(strs);

  return 0;
}