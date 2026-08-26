#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int MaxProd(vector<int> &arr)
{
  int n = arr.size();

  int ans = arr[0];

  for (int i = 0; i < n; i++)
  {
    int prod = 1;
    for (int j = i; j < n; j++)
    {
      prod *= arr[j];
      ans = max(ans, prod);
    }
  }
  return ans;
}

int MaxProd2(vector<int> &arr)
{
  int n = arr.size();

  int maxi = arr[0];
  int mini = arr[0];
  int ans = arr[0];

  for (int i = 1; i < n; i++)
  {

    if (arr[i] < 0)
    {
      swap(maxi, mini);
    }
    maxi = max(arr[i], maxi * arr[i]);
    mini = min(arr[i], mini * arr[i]);

    ans = max(maxi, ans);
  }
  return ans;
}

int main()
{
  vector<int> arr = {2, 3, -2, 4};
  cout << MaxProd(arr) << endl;

  cout << MaxProd2(arr);
}