#include <iostream>
#include <vector>
using namespace std;

int insertPos(vector<int> &arr, int x)
{
  int n = arr.size();

  // binary search

  int low = 0;
  int high = n - 1;
  int ans = n;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (arr[mid] >= x)
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

int insertPos2(vector<int> &arr, int low, int high, int x)
{
  int n = arr.size();
  int ans = n;
  if (low > high)
  {
    return ans;
  }

  int mid = low + (high - low) / 2;
  if (arr[mid] >= x)
  {
    int ans = insertPos2(arr, low, mid - 1, x);

    if (ans == arr.size())
    {
      return mid;
    }
    return ans;
  }
  else
  {
    return insertPos2(arr, mid + 1, high, x);
  }
}

int main()
{
  vector<int> arr = {1, 3, 5, 6};
  int n = arr.size();
  int low = 0;
  int high = n - 1;
  int x = 4;

  cout << insertPos(arr, x);
  cout << insertPos2(arr, low, high, x);

  return 0;
}