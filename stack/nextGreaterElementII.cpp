#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
  int n = nums.size();
  vector<int> ans(n, -1);

  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < i + n; j++)
    {
      int idx = j % n;

      if (nums[idx] > nums[i])
      {
        ans[i] = nums[idx];
        break;
      }
    }
  }
  return ans;
}

vector<int> nextGreaterElementsOpt(vector<int> &nums)
{
  int n = nums.size();
  vector<int> ans(n, -1);
  vector<int> st;

  for (int i = 2 * n - 1; i >= 0; i--)
  {
    int idx = i % n;

    // second pass
    while (!st.empty() && st.back() <= nums[idx])
    {
      st.pop_back();
    }
    // first pass
    if (i < n && !st.empty())
    {
      ans[idx] = st.back();
    }

    st.push_back(nums[idx]);
  }
  return ans;
}
int main()
{
  vector<int> nums = {1, 2, 1};

  vector<int> ans = nextGreaterElements(nums);
  vector<int> ans2 = nextGreaterElementsOpt(nums);

  for (int x : ans)
  {
    cout << x << " ";
  }

  cout << endl;

  for (int x : ans2)
  {
    cout << x << " ";
  }

  return 0;
}