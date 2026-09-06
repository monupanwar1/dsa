#include <iostream>
#include <vector>
using namespace std;

int linear(vector<int> &arr, int target)
{
  int n = arr.size();
  int ans = 0;

  for (int i = 0; i < n; i++)
  {
    if (arr[i] * arr[i] <= target)
    {
      ans = arr[i];
    }
    else
    {
      break;
    }
  }
  return ans;
}

int binary(vector<int> &arr, int target)
{
  int low = 0;
  int high = arr.size() - 1;
  int ans;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    if (mid * mid <= target)
    {
      ans = mid;
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return ans;
}

int main()
{
  vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int target = 10;

  cout << linear(arr, target) << endl;
  cout << binary(arr, target) << endl;

  return 0;
}