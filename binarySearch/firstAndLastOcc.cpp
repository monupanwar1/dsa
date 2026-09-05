#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int> &arr, int target)
{
  int first = -1;
  int last = -1;

  int low = 0;
  int high = arr.size() - 1;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
    {
      first = mid;
      high = mid - 1;
    }
    else if (arr[mid] < target)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }

  low = 0;
  high = arr.size() - 1;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
    {
      last = mid;
      low = mid + 1;
    }
    else if (arr[mid] < target)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }

  return {first, last};
}

int main()
{
  vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
  int target = 2;

  vector<int> ans = searchRange(arr, target);

  cout << ans[0] << " " << ans[1];

  return 0;
}
