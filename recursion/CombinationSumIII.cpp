#include <iostream>
#include <vector>
using namespace std;

void solve(int idx, int k, int target,
           vector<int> &temp,
           vector<vector<int>> &ans)
{
  // write your recursion here

  if (target == 0)
  {
    if (temp.size() == k)
    {
      ans.push_back(temp);
    }
    return;
  }
  if (idx > target || target < 0 || temp.size() > k)
  {
    return;
  }
  temp.push_back(idx);
  solve(idx + 1, k, target - idx, temp, ans);
  temp.pop_back();
  solve(idx + 1, k, target, temp, ans);
}

int main()
{
  int k = 3;
  int n = 7;

  vector<int> temp;
  vector<vector<int>> ans;

  solve(1, k, n, temp, ans);

  for (auto &v : ans)
  {
    for (int x : v)
      cout << x << " ";

    cout << endl;
  }

  return 0;
}