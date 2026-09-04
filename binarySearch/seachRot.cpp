#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &arr, int target)
{
  int n = arr.size();

  for (int i = 0; i < n; i++)
  {
    if (arr[i] == target)
    {
      return i;
    }
  }

  return -1;
}

int search2(vector<int> &arr, int target)
{
  int n = arr.size();

  int low = 0;
  int high = n - 1;

  while (low <= high)
  {

    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
    {
      return mid;
    }

    // left half

    if (arr[low] <= arr[mid])
    {
      if (arr[low] <= target && target <= arr[mid])
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
    else
    {
      if (arr[mid] <= target && target <= arr[high])
      {
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }
  }
  return -1;
}

int main()
{
  vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
  int target = 0;

  cout << search(arr, target) << endl;
  cout << search2(arr, target) << endl;

  return 0;
}