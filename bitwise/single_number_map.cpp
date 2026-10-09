#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums)
{
  unordered_map<int, int> mp;

  for (int num : nums)
  {
    mp[num]++;
  }

  for (auto it : mp)
  {
    if (it.second == 1)
    {
      return it.first;
    }
  }
  return -1;
}

int singleNumber2(vector<int> &nums)
{
  int ans = 0;

  for (int num : nums)
  {
    ans ^= num;
  }

  return ans;
}

int main()
{
  vector<int> nums = {4, 1, 2, 1, 2};

  cout << singleNumber(nums) << endl;
  cout << singleNumber2(nums) << endl;
}