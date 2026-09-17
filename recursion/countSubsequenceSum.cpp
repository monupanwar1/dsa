#include <iostream>
#include <vector>
using namespace std;

int countSubsequence(int idx, vector<int> &nums, int target)
{
  int n = nums.size();

  if (target == 0)
  {
    return 1;
  }

  if (target < 0 || idx == n)
  {
    return false;
  }

  int path1 = countSubsequence(idx + 1, nums, target - nums[idx]);
  int path2 = countSubsequence(idx + 1, nums, target);

  return path1 + path2;
}

int main()
{
  vector<int> nums = {1, 2, 3};
  int target = 3;

  int ans = countSubsequence(0, nums, target);

  cout << ans << endl;

  return 0;
}