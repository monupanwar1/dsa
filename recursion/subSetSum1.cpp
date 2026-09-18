#include <iostream>
#include <vector>
using namespace std;

void subSetSumOne(int idx, vector<int> &nums, int sum, vector<int> &ans)
{

  if (idx == nums.size())
  {
    ans.push_back(sum);
    return;
  };

  // take

  subSetSumOne(idx + 1, nums, nums[idx] + sum, ans);

  // not take
  subSetSumOne(idx + 1, nums, sum, ans);
}

int main()
{

  vector<int> nums = {1, 2, 3, 4};

  int sum;

  vector<int> ans;

  subSetSumOne(0, nums, 0, ans);

  for (auto it : ans)
  {
    cout << it << endl;
  }

  return 0;
}
