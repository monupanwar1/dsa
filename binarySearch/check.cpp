#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> &arr, int target)
{
  int n = arr.size();
  int left = 0;
  int right = n - 1;

  while (left <= right)
  {
    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
    {
      return true;
    }
    else if (target > arr[mid])
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }
  return false;
}

bool check2(vector<int> &arr, int low, int high, int target)
{
  int n = arr.size();
  int left = 0;
  int right = n - 1;

  int mid = left + (right - left) / 2;

  if (left > right)
  {
    return false;
  }
  if (arr[mid] == target)
  {
    return true;
  }
  else if (target > arr[mid])
  {
    return check2(arr, mid + 1, high, target);
  }
  else
  {
    return check2(arr, low, mid - 1, target);
  }
}

int main()
{
  vector<int> arr = {1, 3, 5, 7, 9, 11, 13};
  int low = 0;
  int high = arr.size() - 1;

  int target = 7;

  cout << check(arr, target) << endl;
  cout << check2(arr, low, high, target);

  return 0;
}