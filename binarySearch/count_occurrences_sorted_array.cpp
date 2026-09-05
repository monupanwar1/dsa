#include <iostream>
#include <vector>
using namespace std;

int noOfOCC(vector<int> &arr, int target)
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

  return last - first + 1;
}

int main()
{
  vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
  int target = 2;

  cout << noOfOCC(arr, target);

  return 0;
}
