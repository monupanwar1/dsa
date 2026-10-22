#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int> &fruits)
{
  int n = fruits.size();
  int maxLen = 0;

  for (int i = 0; i < n; i++)
  {
    set<int> st;
    for (int j = i; j < n; j++)
    {
      st.insert(fruits[j]);

      if (st.size() > 2)
      {
        break;
      }
      maxLen = max(maxLen, j - i + 1);
    }
  }
  return maxLen;
}

int totalFruitOpt(vector<int> &fruits)
{
  int n = fruits.size();
  int left = 0;
  int right = 0;
  int maxLen = 0;
  unordered_map<int, int> mp;

  while (right < n)
  {
    mp[fruits[right]]++;

    while (mp.size() > 2)
    {
      mp[fruits[left]]--;

      if (mp[fruits[left]] == 0)
      {
        mp.erase(fruits[left]);
      }
      left++;
    }
    maxLen = max(maxLen, right - left + 1);
    right++;
  }

  return maxLen;
}

int main()
{
  vector<int> fruits = {1, 2, 1, 2, 3};

  cout << totalFruit(fruits) << endl;
  cout << totalFruitOpt(fruits) << endl;

  return 0;
}