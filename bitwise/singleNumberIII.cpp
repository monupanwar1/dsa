#include <bits/stdc++.h>
using namespace std;

vector<int> singleNumberBrute(vector<int> &nums)
{
  unordered_map<int, int> mp;
  vector<int> ans;

  for (auto num : nums)
  {
    mp[num]++;
  }

  for (auto it : mp)
  {
    if (it.second == 1)
    {
      ans.push_back(it.first);
    }
  }
  return ans;
}

vector<int> singleNumberOptimal(vector<int> &nums)
{
  int xor1 = 0;

  for (auto num : nums)
  {
    xor1 = xor1 ^ num;
  }

  // check ith rightmost bit

  int rightmostBit = (xor1 & (xor1 - 1)) ^ xor1;

  int b1 = 0;
  int b2 = 0;

  for (int num : nums)
  {
    if (num & rightmostBit)
    {
      b1 = b1 ^ num;
    }
    else
    {
      b2 = b2 ^ num;
    }
  }
  return {b1, b2};
}
  int main()
  {
    vector<int> nums = {1, 2, 1, 3, 2, 5};

    vector<int> ans = singleNumberBrute(nums);

    for (int num : ans)
    {
      cout << num << " ";
    }

    vector<int> ans2 = singleNumberOptimal(nums);

    for (int num : ans2)
    {
      cout << num << " ";
    }

    return 0;
  }
