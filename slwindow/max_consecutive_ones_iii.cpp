#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int> &nums, int k)
{
  int n = nums.size();
  int maxLen = 0;

  for (int left = 0; left < n; left++)
  {
    int zeros = 0;

    for (int right = left; right < n; right++)
    {
      if (nums[right] == 0)
      {
        zeros++;
      }
      if (zeros > k)
      {
        break;
      }
      maxLen = max(maxLen, right - left + 1);
    }
  }
  return maxLen;
}

int longestOnesOpt(vector<int> &nums, int k)
{
  int n = nums.size();
  int left = 0, right = 0;
  int maxLen = 0;
  int zeros = 0;

  while (right < n)
  {
    if (nums[right] == 0)
    {
      zeros++;
    }
    while (zeros > k)
    {
      if (nums[left] == 0)
      {
        zeros--;
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
  vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
  int k = 2;

  cout << longestOnes(nums, k) << endl;
  cout << longestOnesOpt(nums, k) << endl;
}