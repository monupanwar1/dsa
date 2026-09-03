#include <iostream>
#include <vector>
using namespace std;

int lowerBound(vector<int> &arr, int &target)
{
  int n = arr.size();
  int low = 0;
  int high = n - 1;
  int ans = n;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (arr[mid] >= target)
    {
      ans = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return ans;
}

int lowerBound2(vector<int> &arr, int low, int high, int target)
{

  if (low > high)
  {
    return arr.size();
  }

  int mid = low + (high - low) / 2;

  if (arr[mid] >= target)
  {
    int ans = lowerBound2(arr, low, mid - 1, target);

    if (ans == arr.size())
      return mid;

    return ans;
  }
  else
  {
    return lowerBound2(arr, mid + 1, high, target);
  }
}
int main()
{
  vector<int> arr = {1, 3, 5, 7, 9, 11, 13};
  int low = 0;
  int high = arr.size() - 1;

  int target = 4;

  cout << lowerBound(arr, target) << endl;
  cout << lowerBound2(arr, low, high, target);
}