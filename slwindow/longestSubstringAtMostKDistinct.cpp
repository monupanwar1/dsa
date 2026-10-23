#include <bits/stdc++.h>
using namespace std;

int longestKSubstr(string s, int k)
{
  int n = s.size();
  int maxLen = 0;

  for (int i = 0; i < n; i++)
  {
    unordered_set<char> st;
    for (int j = i; j < n; j++)
    {
      st.insert(s[j]);

      if (st.size() > k)
      {
        break;
      }
      maxLen = max(maxLen, j - i + 1);
    }
  }
  return maxLen;
}

int longestSubstrOpt(string s, int k)
{
  int n = s.size();
  int left = 0;
  int right = 0;
  int maxLen = 0;
  unordered_map<char, int> mpp;

  while (right < n)
  {
    mpp[s[right]]++;

    while (mpp.size() > k)
    {
      mpp[s[left]]--;

      if (mpp[s[left]] == 0)
      {
        mpp.erase(s[left]);
      }
      left++;
    }
    maxLen = max(maxLen, right - left + 1);
    right++;
  }
  return maxLen;
};
int main()
{
  string s = "aababbca";
  int k = 2;

  cout << longestKSubstr(s, k) << endl;
  cout << longestSubstrOpt(s, k) << endl;

  return 0;
}