#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool cmp(pair<char, int> a, pair<char, int> b)
{
  if (a.second != b.second)
  {
    // Higher frequency first
    return a.second > b.second;
  }
  // alpha
  return a.first < b.first;
}

int main()
{
  string s = "ttrree";

  unordered_map<char, int> mp;

  for (char ch : s)
  {
    mp[ch]++;
  }
  vector<pair<char, int>> ans;

  for (auto it : mp)
  {
    ans.push_back(it);
  }

  sort(ans.begin(), ans.end(), cmp);

  for (auto it : ans)
  {
    cout << it.first << " " << it.second << endl;
  }
}
