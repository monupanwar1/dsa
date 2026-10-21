#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
  int n = s.size();
  int maxLen = 0;

  for (int i = 0; i < n; i++)
  {
    unordered_set<char> st;

    for (int j = i; j < n; j++)
    {
      if (st.find(s[j]) != st.end())
      {
        break;
      }

      st.insert(s[j]);

      maxLen = max(maxLen, j - i + 1);
    }
  }
  return maxLen;
}

int lengthOpt(string s)
{
  unordered_set<char> st;
  int left = 0;
  int right = 0;
  int maxLen = 0;
  int n = s.size();

  while (right < n)
  {
    // dup found
    if (st.find(s[right]) != st.end())
    {
      st.erase(s[left]);
      left++;
    }
    else
    {
      st.insert(s[right]);
      maxLen = max(maxLen, right - left + 1);
      right++;
    }
  }

  return maxLen;
}

int main()
{
  string s = "abcabcbb";
  cout << lengthOfLongestSubstring(s) << endl;
  cout << lengthOpt(s) << endl;
  return 0;
}