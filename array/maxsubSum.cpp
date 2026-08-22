#include <iostream>
#include <vector>
using namespace std;

int subArrSum(vector<int> &arr)
{
  int n = arr.size();
  int maxi = INT32_MIN;

  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      int sum = 0;
      for (int k = i; k <= j; k++)
      {
        sum += arr[k];
      }
      maxi = max(sum, maxi);
    }
  }
  return maxi;
};

int main()
{
  vector<int> arr = {4, 7, 1, -9, 3, 6, -2};

  int ans = subArrSum(arr);

  cout << ans;

  cout << endl;
}