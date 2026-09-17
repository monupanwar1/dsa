#include <iostream>
#include <vector>
using namespace std;

int solve(int idx, vector<int> &nums, int target,
          vector<int> &current, vector<vector<int>> &ans)
{
  // Target reached
  if (target == 0)
  {
    ans.push_back(current);
    return 1;
  }

  if (target < 0 || idx == nums.size())
  {
    return 0;
  }

  current.push_back(nums[idx]);
  // same can be resused
  int path1 = solve(idx, nums, target - nums[idx], current, ans);

  current.pop_back();
  // not take move
  int path2 = solve(idx + 1, nums, target, current, ans);

  return path1 + path2;
}

int main()
{
  vector<int> nums = {2, 3, 6, 7};
  int target = 7;

  vector<int> current;
  vector<vector<int>> ans;

  int final = solve(0, nums, target, current, ans);

  cout << "Number of combinations: " << final << endl;

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