#include <bits/stdc++.h>
using namespace std;

int singleNumber_brute(vector<int> &nums)
{

  unordered_map<int, int> mp;

  for (int num : nums)
  {
    mp[num]++;
  };

  for (auto it : mp)
  {
    if (it.second == 1)
    {
      return it.first;
    }
  }

  return -1;
};

int singleNumber_optimized(vector<int> &nums)
{
  int ans = 0;

  for (int i = 0; i < 32; i++)
  {
    int count = 0;

    for (int num : nums)
    {
      if (num & (1 << i))
      {
        count++;
      }
    }

    if (count % 3 != 0)
    {
      ans = ans | (1 << i);
    }
  }

  return ans;
}

int main()
{
  vector<int> nums = {2, 2, 3, 2};

  cout << singleNumber_brute(nums) << endl;
  cout << singleNumber_optimized(nums) << endl;

  return 0;
}
