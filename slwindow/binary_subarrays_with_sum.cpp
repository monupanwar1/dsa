#include <bits/stdc++.h>
using namespace std;

int numSubarraysWithSum(vector<int> &nums, int goal)
{
  int n = nums.size();
  int count = 0;

  for (int i = 0; i < n; i++)
  {
    int sum = 0;

    for (int j = i; j < n; j++)
    {
      sum += nums[j];

      if (sum == goal)
      {
        count++;
      }
      if (sum > goal)
      {
        break;
      }
    }
  }

  return count;
}

int atMost(vector<int> &nums, int goal)
{
  if (goal < 0)
  {
    return 0;
  }
  int n = nums.size();
  int left = 0, right = 0;
  int count = 0;
  int sum = 0;

  while (right < n)
  {
    sum += nums[right];

    while (sum > goal)
    {
      sum -= nums[left];
      left++;
    }
    count += right - left + 1;
    right++;
  }

  return count;
}

int numSubarraysWithSumOpt(vector<int> &nums, int goal)
{
  return atMost(nums, goal) - atMost(nums, goal - 1);
}
int main()
{
  vector<int> nums = {1, 0, 1, 0, 1};
  int goal = 2;

  cout << numSubarraysWithSum(nums, goal) << endl;
  cout << numSubarraysWithSumOpt(nums, goal) << endl;

  return 0;
}