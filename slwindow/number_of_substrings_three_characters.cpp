#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s)
{
  int n = s.size();
  int count = 0;

  for (int i = 0; i < n; i++)
  {
    int freq[3] = {0};

    for (int j = i; j < n; j++)
    {
      freq[s[j] - 'a']++;

      if (freq[0] > 0 && freq[1] > 0 && freq[2] > 0)
      {
        count++;
      }
    }
  }
  return count;
}

int numberOfSubstringsOpt(string s)
{
  int n = s.size();
  int left = 0, right = 0;
  int count = 0;
  int freq[3] = {0};

  while (right < n)
  {

    freq[s[right] - 'a']++;

    while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0)
    {
      count += n - right;

      freq[s[left] - 'a']--;
      left++;
    }
    right++;
  }
  return count;
}

int main()
{
  string s = "abcabc";

  cout << numberOfSubstrings(s) << endl;
  cout << numberOfSubstringsOpt(s) << endl;

  return 0;
}