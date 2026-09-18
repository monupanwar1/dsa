#include <iostream>
#include <vector>
using namespace std;

int check(int idx, vector<int> &nums, int target)
{
  int n = nums.size();

  if (target == 0)
  {
    return 1;
  }

  if (idx == n || target < 0)
  {
    return 0;
  }

  int path = check(idx + 1, nums, target - nums[idx]);

  int path2 = check(idx + 1, nums, target);

  return path || path2;
}

int main()
{

  vector<int> nums = {1, 2, 3, 4};
  int target = 6;

  int ans = check(0, nums, target);

  cout << ans << endl;

  return 0;
}
