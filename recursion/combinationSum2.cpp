#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int idx, vector<int> &nums, int target,
           vector<int> &current, vector<vector<int>> &ans)
{
  // Target reached
  if (target == 0)
  {
    ans.push_back(current);
    return;
  }

  if (target < 0 || idx == nums.size())
  {
    return;
  }

  current.push_back(nums[idx]);
  // same can be resused
  solve(idx + 1, nums, target - nums[idx], current, ans);

  current.pop_back();
  // not take move with eliminate duplicate

  for (int j = idx + 1; j < nums.size(); j++)
  {
    if (nums[j] != nums[idx])
    {
      solve(j, nums, target, current, ans);
      break;
    }
  }
}

int main()
{
  vector<int> nums = {2, 3, 4, 6, 7};
  int target = 7;

  sort(nums.begin(), nums.end());

  vector<int>
      current;
  vector<vector<int>> ans;

  solve(0, nums, target, current, ans);

  // cout << "Number of combinations: " << final << endl;

  for (auto combination : ans)
  {
    cout << "[";
    for (int x : combination)
    {
      cout << x << " ";
    }
    cout << "]";
  }

  return 0;
}