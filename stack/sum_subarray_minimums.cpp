#include <bits/stdc++.h>
using namespace std;

int sumSubarrayMins(vector<int> &arr)
{
  int n = arr.size();
  long long ans = 0;
  int mod = 1e9 + 7;

  for (int i = 0; i < n; i++)
  {
    int mini = INT_MAX;
    for (int j = i; j < n; j++)
    {
      mini = min(mini, arr[j]);
      ans = (ans + mini) % mod;
    }
  }
  return ans;
}

int main()
{
  vector<int> arr = {3, 1, 2, 4};

  cout << sumSubarrayMins(arr) << endl;

  return 0;
}