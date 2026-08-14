#include <iostream>
#include <vector>
using namespace std;

vector<int> reArrSign(vector<int> &arr)
{
  int n = arr.size();
  vector<int> ans(n);
  vector<int> neg;
  vector<int> pos;

  for (int i = 0; i < n; i++)
  {
    if (arr[i] >= 0)
    {
      pos.push_back(arr[i]);
    }
    else
    {
      neg.push_back(arr[i]);
    }
  }

  for (int i = 0; i < n / 2; i++)
  {
    ans[2 * i] = pos[i];
    ans[2 * i + 1] = neg[i];
  }
  return ans;
}

int main()
{
  vector<int> arr = {3, 1, -2, -5, 2, -4};
  vector<int> ans = reArrSign(arr);

  for (auto it : ans)
  {
    cout << it << " ";
  }
  return 0;
}