#include <bits/stdc++.h>
using namespace std;

long long sumSubarrayRanges(vector<int> &nums)
{
  int n = nums.size();
  long long ans = 0;

  for (int i = 0; i < n; i++)
  {
    int mini = INT_MAX;
    int maxi = INT_MIN;

    for (int j = i; j < n; j++)
    {
      mini = min(mini, nums[j]);
      maxi = max(maxi, nums[j]);
      ans += (maxi - mini);
    }
  }
  return ans;
}

vector<int> findPSE(vector<int> &nums)
{
  int n = nums.size();
  vector<int> pse(n);

  stack<int> st;

  for (int i = 0; i < n; i++)
  {
    while (!st.empty() && nums[st.top()] >= nums[i])
    {
      st.pop();
    }
    pse[i] = st.empty() ? -1 : st.top();
    st.push(i);
  }

  return pse;
}

vector<int> findNSE(vector<int> &nums)
{
  int n = nums.size();
  vector<int> nse(n);

  stack<int> st;

  for (int i = n - 1; i >= 0; i--)
  {
    while (!st.empty() && nums[st.top()] > nums[i])
    {
      st.pop();
    }

    nse[i] = st.empty() ? n : st.top();
    st.push(i);
  }

  return nse;
}

// Previous Greater Element
vector<int> findPGE(vector<int> &nums)
{
  int n = nums.size();
  vector<int> pge(n);
  stack<int> st;

  for (int i = 0; i < n; i++)
  {
    while (!st.empty() && nums[st.top()] <= nums[i])
    {
      st.pop();
    }

    pge[i] = st.empty() ? -1 : st.top();
    st.push(i);
  }

  return pge;
}

// Next Greater Element
vector<int> findNGE(vector<int> &nums)
{
  int n = nums.size();
  vector<int> nge(n);
  stack<int> st;

  for (int i = n - 1; i >= 0; i--)
  {
    while (!st.empty() && nums[st.top()] < nums[i])
    {
      st.pop();
    }

    nge[i] = st.empty() ? n : st.top();
    st.push(i);
  }

  return nge;
}

long long subArrayRangesOpt(vector<int> &nums)
{
  int n = nums.size();

  vector<int> pse = findPSE(nums);
  vector<int> nse = findNSE(nums);
  vector<int> pge = findPGE(nums);
  vector<int> nge = findNGE(nums);

  long long sumMin = 0;
  long long sumMax = 0;

  for (int i = 0; i < n; i++)
  {
    long long minCount =
        (i - pse[i]) * 1LL * (nse[i] - i);

    long long maxCount =
        (i - pge[i]) * 1LL * (nge[i] - i);

    sumMin += nums[i] * minCount;
    sumMax += nums[i] * maxCount;
  }

  return sumMax - sumMin;
}

int main()
{
  vector<int> nums = {1, 2, 3};

  cout << sumSubarrayRanges(nums) << endl;
  cout << subArrayRangesOpt(nums) << endl;

  return 0;
}
