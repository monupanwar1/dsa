
#include <bits/stdc++.h>
using namespace std;

void solve(int idx, vector<int> &arr, vector<int> &list, vector<vector<int>> &ans)
{

  if (idx == arr.size())
  {
    ans.push_back(list);
    return;
  }

  list.push_back(arr[idx]);
  solve(idx + 1, arr, list, ans);

  list.pop_back();

  solve(idx + 1, arr, list, ans);
}

// brute
// int main()
// {
//   vector<int> arr = {1, 2, 3};
//   vector<vector<int>> ans;
//   vector<int> list;

//   solve(0, arr, list, ans);

//   for (auto subset : ans)
//   {
//     cout << "[";

//     for (int i : subset)
//     {
//       cout << i << " ";
//     }
//     cout << "]";
//   }
//   return 0;
// }

vector<vector<int>> powerSet(vector<int> &arr)
{
  int n = arr.size();
  vector<vector<int>> ans;

  int subset = (1 << n); // 2^n subset

  for (int mask = 0; mask < subset; mask++)
  {
    vector<int> list;

    for (int i = 0; i < subset; i++)
    {
      // check set bits
      if (mask & (1 << i))
      {
        list.push_back(arr[i]);
      }
    }

    ans.push_back(list);
  }
  return ans;
}

int main()
{
  vector<int> arr = {1, 2, 3};

  vector<vector<int>> ans = powerSet(arr);

  for (auto subset : ans)
  {
    cout << "[ ";
    for (int x : subset)
    {
      cout << x << " ";
    }
    cout << "]\n";
  }

  return 0;
}