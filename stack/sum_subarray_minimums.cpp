#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int sumSubarrayMins(vector<int> &arr)
{
  int n = arr.size();
  long long ans = 0;

  for (int i = 0; i < n; i++)
  {
    int mini = INT_MAX;
    for (int j = i; j < n; j++)
    {
      mini = min(mini, arr[j]);
      ans = (ans + mini) % MOD;
    }
  }
  return ans;
}

vector<int> findPSE(vector<int> &arr)
{
  int n = arr.size();
  stack<int> st;
  vector<int> pse(n);

  for (int i = 0; i < n; i++)
  {
    while (!st.empty() && arr[st.top()] > arr[i])
    {
      st.pop();
    }

    pse[i] = st.empty() ? -1 : st.top();

    st.push(i);
  }
  return pse;
}

vector<int> findNSE(vector<int> &arr)
{
  int n = arr.size();
  stack<int> st;
  vector<int> nse(n);

  for (int i = n - 1; i >= 0; i--)
  {
    while (!st.empty() && arr[st.top()] > arr[i])
    {
      st.pop();
    }

    nse[i] = st.empty() ? n : st.top();

    st.push(i);
  }
  return nse;
}

int sumSubarrayMinsOpt(vector<int> &arr)
{
  int n = arr.size();
  vector<int> pse = findPSE(arr);
  vector<int> nse = findNSE(arr);

  long long ans = 0;

  for (int i = 0; i < n; i++)
  {

    long long left = i - pse[i];
    long long right = nse[i] - i;

    long long contribution = arr[i] * left % MOD;
    contribution = contribution * right % MOD;

    ans = (ans + contribution) % MOD;
  }

  return ans;
}

int main()
{
  vector<int> arr = {3, 1, 2, 4};

  cout << sumSubarrayMins(arr) << endl;

  cout << "Sum of Subarray Minimums: "
       << sumSubarrayMinsOpt(arr) << endl;

  return 0;
}