#include <iostream>
#include <vector>
using namespace std;

int check(int idx, vector<int> &nums, int target)
{
  int n = nums.size();

  // Target reached
  if (target == 0)
  {
    return true;
  }

  // No elements left
  if (idx == n || target < 0)
  {
    return false;
  }

  // Take
  int path = check(idx + 1, nums, target - nums[idx]);

  // Not take
  int path2 = check(idx + 1, nums, target);

  return path || path2;
}

int main()
{

  vector<int> nums = {1, 2, 3, 4};
  int target = 6;

  cout << check(0, nums, target);

  return 0;
}