#include <bits/stdc++.h>
using namespace std;
int longestRepChar(string &s, int k)
{
  int n = s.size();
  int maxLen = 0;

  for (int i = 0; i < n; i++)
  {
    vector<int> freq(26, 0);
    int maxFreq = 0;

    for (int j = i; j < n; j++)
    {
      freq[s[j] - 'A']++;
      maxFreq = max(maxFreq, freq[s[j] - 'A']);

      int window = j - i + 1;
      int changes = window - maxFreq;

      if (changes <= k)
      {
        maxLen = max(maxLen, window);
      }
      else
      {
        break;
      }
    }
    return maxLen;
  }
}

int longestRepCharOpt(string s, int k)
{
  int left = 0;
  int right = 0;
  int maxLen = 0;
  int maxFreq = 0;
  int n = s.size();
  vector<int> freq(26, 0);

  while (right < n)
  {
    freq[s[right] - 'A']++;
    maxFreq = max(maxFreq, freq[s[right] - 'a']);

    while ((right - left + 1) - maxFreq > k)
    {
      freq[s[left] - 'A']--;
      left++;
    }
    maxLen = max(maxLen, right - left + 1);
    right++;
  }
  return maxLen;
}

int main()
{
  string s = "AABABBA";
  int k = 2;

  cout << longestRepChar(s, k) << endl;
  cout << longestRepCharOpt(s, k) << endl;
}