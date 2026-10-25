#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
  int n = s.size();
  int m = t.size();
  int minLen = INT_MAX;
  int start = 0;

  if (m > n)
    return "";

  unordered_map<char, int> need;

  for (char c : t)
  {
    need[c]++;
  }

  for (int i = 0; i < n; i++)
  {
    vector<int> freq(256, 0);

    for (int j = i; j < n; j++)
    {
      freq[s[j]]++;

      bool valid = true;
      for (auto &p : need)
      {
        if (freq[p.first] < p.second)
        {
          valid = false;
          break;
        }
      }
      if (valid)
      {
        int len = j - i + 1;

        if (len < minLen)
        {
          minLen = len;
          start = i;
        }

        break;
      }
    }
  }
  if (minLen == INT_MAX)
    return "";

  return s.substr(start, minLen);
}

string minWindowOpt(string s, string t)
{
  int n = s.size();
  int m = t.size();

  if (m > n)
    return "";

  vector<int> need(256, 0);

  for (char c : t)
    need[c]++;

  int left = 0, right = 0;
  int count = 0;
  int minLen = INT_MAX;
  int start = 0;

  while (right < n)
  {
    if (need[s[right]] > 0)
      count++;

    need[s[right]]--;

    while (count == m)
    {
      if (right - left + 1 < minLen)
      {
        minLen = right - left + 1;
        start = left;
      }

      need[s[left]]++;

      if (need[s[left]] > 0)
        count--;

      left++;
    }

    right++;
  }

  if (minLen == INT_MAX)
    return "";

  return s.substr(start, minLen);
}

int main()
{
  cout << minWindow("ADOBECODEBANC", "ABC") << endl;
  cout << minWindowOpt("ADOBECODEBANC", "ABC") << endl;
  return 0;
}